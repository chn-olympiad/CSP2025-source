#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,x,y,a[101],s,a1;
int main()
{
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 cin>>n>>m;
 for(i=1;i<=n*m;i++)
 {
  cin>>a[i];
 }
 a1=a[1];
 for(i=1;i<=n;i++)
 {
  for(j=i;j<=n;j++)
  {
   if(a[i]<a[j])
   {
    swap(a[i],a[j]);
   }
  }
 }
 for(i=1;i<=n*m;i++)
 {
  if(a[i]==a1)
  {
   s=i;
  }
 }
 y=s%n;
 if(y==0)
 {
  y=1;
 }
 x=(s-y)/n+1;
 cout<<x<<" "<<y;
 return 0;
}
