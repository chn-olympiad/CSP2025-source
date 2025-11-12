#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int b,c,r,p;
int f[999999];
int main()
{
  freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>b>>c;
   cin>>r;
   f[0]=r;
   for(int i=1;i<b*c;i++)
   {
    cin>>f[i];
   }
   for(int i=0;i<b*c;i++)
     {
          for(int j=0;j<b*c-1;j++)
     {
         if(f[j]<f[j+1])
         {
             p=f[j];
             f[j]=f[j+1];
             f[j+1]=p;
         }
     }
     }
     int x=1,y=1;
      for(int i=1;i<=b*c;i++)
   {
      if(x<b&&y%2!=0)
      {
          a[x][y]=f[i-1];
          x++;
      }
      else if(x==b&&y%2!=0)
      {
            a[x][y]=f[i-1];
            y++;
      }
      else if(x>1&&y%2==0)
      {
            a[x][y]=f[i-1];
            x--;
      }
      else if(x==1&&y%2==0)
      {
            a[x][y]=f[i-1];
            y++;
      }
   }
   for(int i=1;i<=b;i++)
   {
      for(int j=1;j<=c;j++)
   {
       if(a[i][j]==r)
       {
           cout<<j<<" "<<i;
           break;
       }
   }
   }
    return 0;
}
