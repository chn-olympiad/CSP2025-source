#include<bits/stdc++.h>
using namespace std;
int main()
{
 freopen("seat.in","r",stdin);
 freopen("seat.out","w",stdout);
 int m,n,d,c,e,f,l=0;
 cin>>n>>m;
 int a[n][m],b[m*n];
 for(int i=1;i<=m*n;i++)
 {
  cin>>b[i];
 }
 c=b[1];
 for(int i=1;i<=m*n;i++)
 {
  for(int j=i;j<=m*n;j++)
  {
   if(b[j]>b[i])
   {
    d=b[j];
    b[j]=b[i];
      b[i]=d;
   }
  }
 }
 for(int i=1;i<=m;i++)
 {
  for(int j=1;j<=n;j++)
  {
   a[i][j]=b[l];
   l++;
   if(b[l]==c)
   {
    e=i;
    f=j;
   }
  }
 }
 cout<<e<<" "<<f;
 return 0;
}
