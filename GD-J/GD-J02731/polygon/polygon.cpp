#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,n,m,a[100010],f[100010],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	sort(a+1,a+1+n);
	sum=1;
	for(long long i=1;i<=n;i++)
	{
		sum=sum*2ll%mod;
	}
	sum=(sum-1+mod)%mod;
	f[0]=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=m;j>a[i];j--)
		{
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
		for(long long j=0;j<=a[i];j++)
		{
			sum=(sum-f[j]+mod)%mod;
		}
		f[a[i]]=(f[a[i]]+f[0])%mod;
	}
	cout<<sum;
	return 0;
}
