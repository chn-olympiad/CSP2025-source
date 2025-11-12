#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
long long x[10000][10000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long i,j,n,m,h=1,k=1,t,w,a[10000],r;
    cin>>n>>m;
    //cout<<n<<" "<<m;
    t=n*m;
    for(i=1;i<=t;i++)
        cin>>a[i];
        r=a[1];
    //for(i=1;i<=n*m;i++)
        //cout<<a[i]<<" ";
        for(i=1;i<t;i++)
    {
     for(j=i+1;j<=t;j++)
     {
         if(a[i]<a[j]){w=a[i];a[i]=a[j];a[j]=w;}
     }
  }
  //for(i=1;i<t;i++){cout<<a[i]<<" ";}
  i=1;
 while(i<=t&&h<=m)
  {
      if(h%2==1)
      {
          for(j=1;j<=n;j++)
            {x[j][h]=a[i];i++;}
      }

      else
      {
          for(j=n;j>=1;j--)
            {x[j][h]=a[i];i++;}
      }
      h++;
   }
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=m;j++)
      {
          //cout<<x[i][j]<<" ";
          if(x[i][j]==r)
            {cout<<j<<" "<<i;}
          }
          //cout<<endl;
   }
   //cout<<x[2][1];
   return 0;
}
