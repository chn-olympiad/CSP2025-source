#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s[11][11];
	int n,m,c;
	int a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i];
	c=a[1];
	sort(&a[1],&a[n*m+1],cmp);
	for(int j=1,sum=1;j<=m;j++)
	{
	  for(int i=1;i<=n;i++,sum++)
	    s[i][j]=a[sum];
	  j++;
	  for(int i=n;i>=1;i--,sum++)
	    s[i][j]=a[sum];
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    if(s[i][j]==c)
	      cout<<j<<" "<<i;
	return 0;
}
