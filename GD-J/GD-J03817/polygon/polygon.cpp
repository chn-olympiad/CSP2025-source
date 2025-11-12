#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998244353;
int n,a[N],f[N],maxn,ans;
int qpow(int ai,int bi)
{
	int s=1;
	while(bi)
	{
		if(bi&1) s=s*ai%mod;
		ai=ai*ai%mod;
		bi>>=1;
	}
	return s;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);ans=(qpow(2,n)+mod-(n*(n-1)/2+n+1)%mod)%mod;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),maxn=max(maxn,a[i]);
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j>=1;j--) ans=(ans+mod-f[j])%mod;
		ans=(ans+i-1)%mod;
		for(int j=maxn;j>=a[i];j--) f[j]=(f[j]+f[j-a[i]])%mod;
	}
	printf("%lld",ans);
	return 0;
}
