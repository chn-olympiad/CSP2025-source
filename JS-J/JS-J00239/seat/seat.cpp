#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,b,c,x,y;
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n*m;i++)
   {
       cin>>a[i];
   }
   b=a[1];
   sort(a+1,a+n*m+1);
   for(int i=1;i<=n*m;i++) if(a[i]==b) c=n*m-i+1;
   y=(c-1)/n+1;
    x=c%n;
   if(x==0) x=n;
   if(y%2==0) x=n-x+1;
   cout<<y<<" "<<x;
   return 0;
}
