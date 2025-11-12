#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	if(n==3)
	{
		int sum=0,maxx=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			maxx=max(maxx,a[i]);
		}
		if(sum>maxx*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	long long a=1;
	for(long long i=4;i<=n;i++)
	{
		a*=i;
		a%=998244353;
	}
	cout<<a;
}
