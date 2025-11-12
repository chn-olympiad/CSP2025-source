#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
     string s;
     cin>>s;
  int num[10];
  for(int i=0;i<=9;i++)num[i]=0;
  for(int i=0;i<s.size();i++){
      if(s[i]=='1')++num[0];
      if(s[i]=='2')++num[1];
      if(s[i]=='3')++num[2];
      if(s[i]=='4')++num[3];
      if(s[i]=='5')++num[4];
      if(s[i]=='6')++num[5];
      if(s[i]=='7')++num[6];
      if(s[i]=='8')++num[7];
      if(s[i]=='9')++num[8];
      if(s[i]=='0')++num[9];
  }
  while(num[8]--)cout<<'9';
  while(num[7]--)cout<<'8';
  while(num[6]--)cout<<'7';
  while(num[5]--)cout<<'6';
  while(num[4]--)cout<<'5';
  while(num[3]--)cout<<'4';
  while(num[2]--)cout<<'3';
  while(num[1]--)cout<<'2';
  while(num[0]--)cout<<'1';
  while(num[9]--)cout<<'0';
  return 0;
}
