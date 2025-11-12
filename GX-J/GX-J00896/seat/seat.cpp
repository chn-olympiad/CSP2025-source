#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,x=1;
  cin>>n>>m;
  int a[n*m+1];
  for(int i=1;i<=n*m+1;i++)
  cin>>a[i];
  for(int i=2;i<=n*m+1;i++)
  if(a[1]<a[i])x++;
  if((x/n+1)%2==1)
  cout<<x/n+1<<x-x/n;
  else cout<<x/n+1<<n-x+x/n+1;
  return 0;
}
