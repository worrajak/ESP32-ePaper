
// mapping suggestion for ESP32, e.g. LOLIN32, see .../variants/.../pins_arduino.h for your board
// NOTE: there are variants with different pins for SPI ! CHECK SPI PINS OF YOUR BOARD
// BUSY -> 4, RST -> 16, DC -> 17, CS -> SS(5), CLK -> SCK(18), DIN -> MOSI(23), GND -> GND, 3.3V -> 3.3V

// include library, include base class, make path known
#include <GxEPD.h>

#include <GxGDEW0154Z17/GxGDEW0154Z17.h>  // 1.54" b/w/r 152x152

#include GxEPD_BitmapExamples
#include "IMG_0001.h"

// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>


#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

GxIO_Class io(SPI, /*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16); // arbitrary selection of 17, 16
GxEPD_Class display(io, /*RST=*/ 16, /*BUSY=*/ 4); // arbitrary selection of (16), 4

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init(115200); // enable diagnostic output on Serial

  Serial.println("setup done");

  //showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
  showBitmapExample();
}

void loop()
{
  //showFont("FreeMonoBold9pt7b", &FreeMonoBold9pt7b);
  //showBitmapExample();
  //delay(2000);
  //display.drawCornerTest();
  //delay(2000);
  //display.drawPaged(showFontCallback);
  //delay(10000);
}


#if defined(_GxGDEW0154Z17_H_)
#define HAS_RED_COLOR
void showBitmapExample()
{
  //display.drawExamplePicture(gImage_IMG_0001, BitmapExample2, sizeof(gImage_IMG_0001), sizeof(BitmapExample2));
  //delay(5000);
  //display.drawExamplePicture(BitmapExample1, BitmapExample2, sizeof(BitmapExample1), sizeof(BitmapExample2));
  //delay(5000);
  //display.drawExamplePicture(BitmapExample3, BitmapExample4, sizeof(BitmapExample1), sizeof(BitmapExample2));
  //delay(5000);
  display.drawBitmap(gImage_IMG_0001, sizeof(gImage_IMG_0001));
  delay(5000);
}
#endif

void showFont(const char name[], const GFXfont* f)
{
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  //display.println(name);
  display.println("EPD Display");
  display.println(" ");
  display.println("PQ Lab.");  
  display.update();
  delay(5000);
}

void showFontCallback()
{
  const char* name = "FreeMonoBold9pt7b";
  const GFXfont* f = &FreeMonoBold9pt7b;
  display.fillScreen(GxEPD_WHITE);
  display.setTextColor(GxEPD_RED);
  display.setFont(f);
  display.setCursor(0, 0);
  display.println();
  display.println(name);
  display.println(" !\"#$%&'()*+,-./");
  display.println("0123456789:;<=>?");
  display.println("@ABCDEFGHIJKLMNO");
  display.println("PQRSTUVWXYZ[\\]^_");
#if defined(HAS_RED_COLOR)
  display.setTextColor(GxEPD_RED);
#endif
  display.println("`abcdefghijklmno");
  display.println("pqrstuvwxyz{|}~ ");
}

void drawCornerTest()
{
  display.drawCornerTest();
  delay(5000);
  uint8_t rotation = display.getRotation();
  for (uint16_t r = 0; r < 4; r++)
  {
    display.setRotation(r);
    display.fillScreen(GxEPD_WHITE);
    display.fillRect(0, 0, 8, 8, GxEPD_BLACK);
    display.fillRect(display.width() - 18, 0, 16, 16, GxEPD_BLACK);
    display.fillRect(display.width() - 25, display.height() - 25, 24, 24, GxEPD_BLACK);
    display.fillRect(0, display.height() - 33, 32, 32, GxEPD_BLACK);
    display.update();
    delay(5000);
  }
  display.setRotation(rotation); // restore
}


