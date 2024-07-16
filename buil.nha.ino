#include <Servo.h>
//phongkhach
int nutnhan = 1;
unsigned char onoff = 0;
int led = 3;
int cambien = 2;
int servo = 4;
int gocsv1 ;
int timeled = 100000;
int timecua = 5000;
unsigned long hientai = 0 ;
unsigned long thoigian;
//cambienmua
int cambienmua = 5;
int servo2 = 6;
int vitri = 163;

// cambienlua va gas
int cambienlua = 7;
int buzzlua = 8;
int buzzphong = 10;
int cambiengas = 9;
int timebuzz = 10000;
unsigned long hientaibuzz = 0 ;
int timebuzz2 = 10000;
unsigned long hientaibuzz2 = 0 ;

//cambienphong
int ledphong = 11;
int cambienphong = 12;
int timeledphong = 20000;
unsigned long hientailedphong = 0 ;
  unsigned long hientaichay = 0 ;
  int timechonhac = 30000 ;
  int cc = 1;
struct MusicStruct {
  int A = 550;
  int As = 582;
  int B = 617;
  int C = 654;
  int Cs = 693;
  int D = 734;
  int Ds = 777;
  int E = 824;
  int F = 873;
  int Fs = 925;
  int G = 980;
  int Gs = 1003;
  int A2 = 1100;
  int A2s = 1165;
  int B2 = 1234;
  int C3 = 1308;
  int C3s = 1385;
  int D3 = 1555;
}Music;
struct LengthStruct {
  float half = 0.5;
  float one = 1.0;
  float one_half = 1.5;
  float two = 2.0;
  float two_half = 2.5;
}Length;
int tempo = 400;

Servo myservo2;
Servo myservo;
void setup() {
  //phongkhach
 myservo.attach(servo);
pinMode( led , OUTPUT );
pinMode ( nutnhan , INPUT_PULLUP);
pinMode( cambien ,INPUT );
digitalWrite( led , LOW);
//phoido
 myservo2.attach(servo2);
pinMode( cambienmua, INPUT );
//cambienlua
pinMode( cambienlua , INPUT ) ;
 pinMode( buzzlua , OUTPUT ) ;
 pinMode( buzzphong, OUTPUT);
 pinMode( cambiengas, INPUT);

 //cambienphong
 pinMode( cambienphong ,INPUT );
 pinMode( ledphong,OUTPUT);
}

void setTone(int pin, int note, int duration) {
  tone(pin, note, duration);
  delay(duration);
  noTone(pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  //phongkhach
   thoigian = millis();
if ( digitalRead(cambien)==1 )
{
  digitalWrite(led,HIGH);
  myservo.write(160);
  gocsv1 = myservo.read();
   hientai =millis();
}
if ( thoigian - hientai >= timeled )
  {
    if ( digitalRead(led)==HIGH )
    {
      digitalWrite(led, LOW);
    }
  }
 if( thoigian - hientai >= timecua)
 {
  if ( gocsv1 == 160 )
  {
    myservo.write(30);
    gocsv1 = myservo.read();
  }
 }
  if ( digitalRead(nutnhan) == LOW ){
    delay(20);
    if ( digitalRead(nutnhan)== LOW) {
      if ( onoff == 0) {
        onoff = 1;
        digitalWrite(led , HIGH );
      }
      else {
        onoff = 0 ;
        digitalWrite ( led , LOW);
      }
    }
    while ( digitalRead(nutnhan) == LOW );
  }
  //phoido
  if ( digitalRead(cambienmua) == 1)
      {
      if ( vitri == 40 )
        {
        for( vitri = 40 ; vitri < 163 ; vitri++)
        {
        myservo2.write(vitri);
        delay(10);
        }
      }
      }
      else {
        if ( vitri == 163 ) 
        {
        for( vitri = 163 ; vitri > 40 ; vitri--)
        {
          myservo2.write(vitri);
          delay(10);
        }
       }
      }
 //cambienlua va gas
      if ((digitalRead(cambiengas) == 0)|| (digitalRead(cambienlua) == 0) )
  {
    digitalWrite(buzzlua, HIGH);
    hientaibuzz =millis();
      myservo.write(160);
  }
  if ( thoigian - hientaibuzz >= timebuzz )
  {
    if ( (digitalRead( buzzlua )==HIGH) )
    {
      digitalWrite(buzzlua, LOW);
       myservo.write(30);
    }
  }

  //cambienphong
  if ( digitalRead(cambienphong) == 1)
  {
    if ( cc == 1 )
    {
   hientaichay = millis();
   cc = 2;
     digitalWrite(ledphong,HIGH);
     hientailedphong =millis();
    setTone(buzzphong, Music.B, tempo * Length.one);
  setTone(buzzphong, Music.E, tempo * Length.one_half);
  setTone(buzzphong, Music.G, tempo * Length.half);
  setTone(buzzphong, Music.F, tempo * Length.one);
  setTone(buzzphong, Music.E, tempo * Length.two);
  setTone(buzzphong, Music.B2, tempo * Length.one);
  setTone(buzzphong, Music.A2, tempo * Length.two_half);
  setTone(buzzphong, Music.Fs, tempo * Length.two_half);
  
  setTone(buzzphong, Music.E, tempo * Length.one_half);
  setTone(buzzphong, Music.G, tempo * Length.half);
  setTone(buzzphong, Music.F, tempo * Length.one);
  setTone(buzzphong, Music.Ds, tempo * Length.two);
  setTone(buzzphong, Music.F, tempo * Length.one);
  setTone(buzzphong, Music.B, tempo * Length.two_half);
  }
  if ( (cc ==2) && ( thoigian - hientaichay > timechonhac) )
  {
    hientaichay = millis();
       digitalWrite(ledphong,HIGH);
     hientailedphong =millis();
    setTone(buzzphong, Music.B, tempo * Length.one);
  setTone(buzzphong, Music.E, tempo * Length.one_half);
  setTone(buzzphong, Music.G, tempo * Length.half);
  setTone(buzzphong, Music.F, tempo * Length.one);
  setTone(buzzphong, Music.E, tempo * Length.two);
  setTone(buzzphong, Music.B2, tempo * Length.one);
  setTone(buzzphong, Music.A2, tempo * Length.two_half);
  setTone(buzzphong, Music.Fs, tempo * Length.two_half);
  
  setTone(buzzphong, Music.E, tempo * Length.one_half);
  setTone(buzzphong, Music.G, tempo * Length.half);
  setTone(buzzphong, Music.F, tempo * Length.one);
  setTone(buzzphong, Music.Ds, tempo * Length.two);
  setTone(buzzphong, Music.F, tempo * Length.one);
  setTone(buzzphong, Music.B, tempo * Length.two_half);
  }
  }

  if ( thoigian - hientailedphong >= timeledphong )
  {
    if ( digitalRead( ledphong )==HIGH )
    {
      digitalWrite(ledphong, LOW);
    }
  }

  
      
}
    
