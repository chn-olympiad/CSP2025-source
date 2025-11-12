#include<bits/stdc++.h>
using namespace std;
struct w{
int v1,v2,q1;
}a[1000002];
struct y{
int c1,q2[10005];
}b[12];
int c[10001];
int  n,m,k;
int main()
{
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i].v1>>a[i].v2>>a[i].q1;
       if(a[i].v1=1)
       {
          c[i]=a[i].q1;
       }
   }
   for(int i=1;i<=m;i++)
   {

       cin>>b[i].c1;
       for(int j=1;j<=n;j++)
       {

           cin>>b[i].q2[j];

       }
       for(int x=1;x<=n;x++)
       {
           if(c[j]>=b[i].c1+b[i].q2[x])
           {
               x[i]=b[i].c1+b[i].q2;
           }
       }
   }

    return 0;
}
