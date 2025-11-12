#include<bits/stdc++.h>
using namespace std;
int n,m,x,ark,r,c;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			ark=i;
		}
	}
	if(ark%n==0)
	{
		c=ark/n;
	}
	else
	{
		c=ark/n+1;
	}
	if(c%2)
	{
		r=ark%n;
		if(r==0)
		{
			r=n;
		}
	}
	else
	{
		if(ark%n==0)
		{
			r=1;
		}
		else
		{
			r=n-(ark%n)+1;
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
