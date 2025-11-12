#include <bits/stdc++.h>
using namespace std;
int a[5001];
int f(int x,int y)
{
	if(y==0) return 1;
	else return x*f(x,y-1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,i,j,m,k;
	int y=0;
	int ans=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		y=max(y,a[i]);
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*max(a[1],a[2])&&a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		if(y==1)
		{
			cout<<f(2,n)-n-n*(n-1)/2;
		}
		else cout<<n;
	}
	return 0;
}
