#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],f[5005];
int qpow(int a,int b,int mod)
{
	int sum=1;
	while(b)
	{
		if(b&1) sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return sum;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
	{
		int sum=0,mx=-1e9;
		for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i],mx=max(mx,a[i]);
		if(sum>mx) cout<<1;
		else cout<<0;
	}else
	{
		for(int i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
		int mx=-1e9;
		for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
		if(mx==1)
		{
			int ans=0;
			f[0]=1;
			for(int i=3;i<=n;i++) ans+=(((f[n]*qpow(f[i],mod-2,mod))%mod)*qpow(f[n-i],mod-2,mod)%mod)%mod;
			cout<<ans%mod;
		}else cout<<f[n];
	}
	return 0;
}
