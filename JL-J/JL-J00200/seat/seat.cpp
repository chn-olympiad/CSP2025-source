#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[110],b,c,d;

signed main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==b)
		{
			c=i;
		}
	}
	c=n*m-c+1;
	if(c%n==0)
	{
		d=c/n;
	}
	else
	{
		d=c/n+1;
	}
	if(d%2==0)
	{
		cout<<d<<' '<<n-c%n+1;
	}
	else
	{
		cout<<d<<' '<<c%n;
	}
		return 0;
}
