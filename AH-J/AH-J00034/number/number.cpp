#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000002],b=0,d=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=1000002;i++)
    a[i]=11;
    for(int i=0;i<=1000002;i++)
    {
        if(s[i]==48)//0
        a[i]=s[i]-48;
        if(s[i]==50)//2
        a[i]=s[i]-48;
        if(s[i]==51)//3
        a[i]=s[i]-48;
        if(s[i]==52)//4
        a[i]=s[i]-48;
        if(s[i]==53)//5
        a[i]=s[i]-48;
        if(s[i]==54)//6
        a[i]=s[i]-48;
        if(s[i]==55)//7
        a[i]=s[i]-48;
        if(s[i]==56)//8
        a[i]=s[i]-48;
        if(s[i]==57)//9
        a[i]=s[i]-48;
        if(s[i]==49)//1
        a[i]=s[i]-48;
    }
    b=0;
      for(int i=0;i<=1000002;i++)
      {

          if(a[i]==11)
          {

              break;
          }
        b++;
      }
      for(int l=0;l<=b;l++)
      {
         for(int i=0;i<b-1;i++)
      {
          if(a[i]<a[i+1])
          {
              d=a[i];
              a[i]=a[i+1];
              a[i+1]=d;
          }
      }
      }

      for(int i=0;i<b;i++)
      {
          cout<<a[i];
      }

      //#Shang4Shan3Ruo6Shui4
      //50=2;48=0
      //290es1q0
    fclose(stdin);fclose(stdout);
    return 0;
}
