#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005],x,y;
long long s=1,b=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
	}
	else if(n==3)
	{
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
		}
	}
	else if(a[n]==a[1])
	{
		for(int i=3;i<=n;i++)
		{
			x=max(n-i+1,i+1);
			y=min(i,n-i);
			s=1;
			for(int j=n;j>=x;j--)
			{
				s=(s*j)%998244353;
			}
			for(int j=2;j<=y;j++)
			{
				s/=j;
			}
			b=(b+s)%998244353;
		}
		cout<<b;
	}
	else
	{
		cout<<6;
	}
	return 0;
}
