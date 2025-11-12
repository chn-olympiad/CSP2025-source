#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3)
	{
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		long long ans=0,s=1,m=1;
		for(long long i=3;i<=n;i++)
		{
			s=1;
			m=1;
			for(long long j=500;j>500-i;j--)
			{
				s*=j;
			}
			for(long long j=i;j>=1;j--)
			{
				m*=j;
			}
			ans+=s/m;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}