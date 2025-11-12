#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("number.in","r",stdin);
   freopen("number.out","r",stdout)
   char a[0];
   char b[0];
   int c=0;
   cin>>a;
   for(int i=1;i<=1000;i++)
   {
       if(a[i]==0||1|2|3|4|5|6|7|8|9)
       {
          a[i]=b[i];
       }
       for(int j=i;i<=i;j++)
       {
          if(b[j]<b[j+1])
          {
             c=b[j];
             b[j]=b[j+1];
             b[j+1]=c;
          }
       }
   }
   cout<<b[0];
   return 0;
}