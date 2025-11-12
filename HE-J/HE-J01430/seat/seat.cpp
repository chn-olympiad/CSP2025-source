#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,r,sum=1,n,m,a[105],a1;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			a1=a[1];
		}
		else if(a[i]>a1)
		{
			sum++;
		}
	}
	if(sum%n==0)
	{
		c=sum/n;
	}
	else
	{
		c=sum/n+1;
	}
	if(c%2==1)
	{
		r=sum%n;
		if(r==0)
		{
			r=n;
		}
	}
	else
	{
		r=sum%n;
		if(r==0)
		{
			r=n;
		}
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
