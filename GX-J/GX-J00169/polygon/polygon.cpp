#include<bits/stdc++.h>
using namespace std;
int a[99999999];
int z;

int b,n,k,a1=1,a2,a3,a4;
int main()
{
freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
   cin>>n;
   int g[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n-1;j++)
   {
      if(a[j]<a[j+1])
      {
          b=a[j];
          a[j]=a[j+1];
          a[j+1]=b;

      }

   }
   }

   for(int i=3;i<=n;i++)
   {

      for(int j=0;j<n-i;j++)
      {
          for(int y=j;y<j+i;y++)
          {
          k=k+a[y];
          }
          if(k>a[j]*2)z++;
      }

   }
   cout<<z*3;
    return 0;
}
