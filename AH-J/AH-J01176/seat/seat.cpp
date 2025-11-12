#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,l,r,a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==x)
		{
			y=n*m-i+1;
		}
	}
	l=(y-1)/n+1;
	if(l%2==1)
	{
		if(y%n==0)
		{
			r=n;
		}
		else
		{
			r=y%n;
		}
	}
	else
	{
		if(y%n==0)
		{
			r=1;
		}
		else
		{
			r=n-y%n+1;
		}
	}
	cout<<l<<" "<<r;
	return 0;
}
