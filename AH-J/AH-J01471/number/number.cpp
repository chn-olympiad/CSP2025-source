#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
int cuan,a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
using namespace std;
int main()
{   string s;
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    cin>>s;
    cuan=s.size();
    for(int i=0;i<=cuan;i++)
    {
       if(s[i]=='1')a1++;
       if(s[i]=='2')a2++;
       if(s[i]=='3')a3++;
       if(s[i]=='4')a4++;
       if(s[i]=='5')a5++;
       if(s[i]=='6')a6++;
       if(s[i]=='7')a7++;
       if(s[i]=='8')a8++;
       if(s[i]=='9')a9++;
       if(s[i]=='0')a0++;
   }
      for(int i=0;i<=cuan;i++)
    {
       if(a9!=0){cout<<'9';a9--;}
       else if(a8!=0){cout<<'8';a8--;}
       else if(a7!=0){cout<<'7';a7--;}
       else if(a6!=0){cout<<'6';a6--;}
       else if(a5!=0){cout<<'5';a5--;}
       else if(a4!=0){cout<<'4';a4--;}
       else if(a3!=0){cout<<'3';a3--;}
       else if(a2!=0){cout<<'2';a2--;}
       else if(a1!=0){cout<<'1';a1--;}
       else if(a0!=0){cout<<'0';a0--;}
   }
    return 0;}

