#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int n=0,a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,i=1;
while(s[n]=='1' || s[n]=='2' || s[n]=='3' || s[n]=='4' || s[n]=='5' || s[n]=='6' || s[n]=='7' || s[n]=='8' || s[n]=='9' || s[n]=='0' || s[n]=='a' || s[n]=='b' || s[n]=='c' || s[n]=='d' || s[n]=='e' || s[n]=='f' || s[n]=='g' || s[n]=='h' || s[n]=='i' || s[n]=='j' || s[n]=='k' || s[n]=='l' || s[n]=='m' || s[n]=='n' || s[n]=='o' || s[n]=='p' || s[n]=='q' || s[n]=='r' || s[n]=='s' || s[n]=='t' || s[n]=='u' || s[n]=='v' || s[n]=='w' || s[n]=='x' || s[n]=='y' || s[n]=='z')
    {if(s[n]=='0')
        a0++;
    else if (s[n]=='1')
        a1++;
    else if (s[n]=='2')
        a2++;
    else if (s[n]=='3')
        a3++;
    else if (s[n]=='4')
        a4++;
    else if (s[n]=='5')
        a5++;
    else if (s[n]=='6')
        a6++;
    else if (s[n]=='7')
        a7++;
    else if (s[n]=='8')
        a8++;
    else if (s[n]=='9')
        a9++;
    n++;
}
for( i=1;i<=a9;i++)
    cout<<9;
for( i=1;i<=a8;i++)
    cout<<8;
for( i=1;i<=a7;i++)
    cout<<7;
for( i=1;i<=a6;i++)
    cout<<6;
for( i=1;i<=a5;i++)
    cout<<5;
for( i=1;i<=a4;i++)
    cout<<4;
for( i=1;i<=a3;i++)
    cout<<3;
for( i=1;i<=a2;i++)
    cout<<2;
for( i=1;i<=a1;i++)
    cout<<1;
for( i=1;i<=a0;i++)
    cout<<0;
return 0;
}
