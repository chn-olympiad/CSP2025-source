#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
return x>y;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0;
char c;
while(cin>>c){
if(c=='9')a9++;
if(c=='8')a8++;
if(c=='7')a7++;
if(c=='6')a6++;
if(c=='5')a5++;
if(c=='4')a4++;
if(c=='3')a3++;
if(c=='2')a2++;
if(c=='1')a1++;
if(c=='0')a0++;
}
for(int i=0;i<a9;i++)cout<<9;
for(int i=0;i<a8;i++)cout<<8;
for(int i=0;i<a7;i++)cout<<7;
for(int i=0;i<a6;i++)cout<<6;
for(int i=0;i<a5;i++)cout<<5;
for(int i=0;i<a4;i++)cout<<4;
for(int i=0;i<a3;i++)cout<<3;
for(int i=0;i<a2;i++)cout<<2;
for(int i=0;i<a1;i++)cout<<1;
for(int i=0;i<a0;i++)cout<<0;
return 0;
}
