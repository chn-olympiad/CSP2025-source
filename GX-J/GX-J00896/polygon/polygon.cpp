#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  int n;
  cin>>n;
  int a[n+1],b[n+1],maxx=0,z=0,s=0;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  for(int i=3;i<=n;i++)
  {
	for(int x=1;x<=i;x++)
	{
	  b[x]=a[x+i-2];
	  if(maxx<b[x])maxx=b[x];
	  s+=b[x];
	}
	if(s>maxx*2) z++;
  }
  cout<<z%958%244%353;
  return 0;
}
