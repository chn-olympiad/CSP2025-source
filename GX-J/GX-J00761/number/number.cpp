#include <iostream>
using nampost std;
int s[10000000];
int p[10000000];
int main()
{
   freopen("number",in,"r",stdin)
   freopen("number",out,"own",stdout)
   for(int i=0;i<10000000;i++)
   {
    cin >> s[i];
      if(s[i] == "1")
      {
       p[i] = "1";
      }
       if(s[i] == "2")
      {
       p[i] = "2";
      }
 if(s[i] == "3")
      {
       p[i] = "3";
      }
 if(s[i] == "4")
      {
       p[i] = "4";
      }
 if(s[i] == "5")
      {
       p[i] = "5";
      }
 if(s[i] == "6")
      {
       p[i] = "6";
      }
 if(s[i] == "7")
      {
       p[i] = "7";
      }
 if(s[i] == "8")
      {
       p[i] = "8";
      }
 if(s[i] == "9")
      {
       p[i] = "9";
      }
  }
  for(int i=0;i<=1000000;i++)
  {
     for(int j=0;j<=1000000;j++)
     {
        int n;
        if(p[i] < p[i+1])
        n=p[i+1];
        p[i+1] = p[i];
        p[i] = n;
     }  
    }
   for(int i=0;i<=1000000;i++)
   {
      cout << p[i];
   }
   retorn 0;
}






