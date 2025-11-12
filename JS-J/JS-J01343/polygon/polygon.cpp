#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],dp[5005],ans;
const ll mod=998244353;
ll qpow(ll x,ll y)
{
	if(!y) return 1;
	ll tmp=qpow(x,y>>1);
	if(y&1) return tmp*tmp%mod*x%mod;
	return tmp*tmp%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);dp[0]=1;
	for(ll i=1;i<=n;i++)
	{
		if(i>=2)
		{
			ll tmp=qpow(2,i-1);
			for(ll j=0;j<=a[i];j++) (tmp+=mod-dp[j])%=mod;
			(ans+=tmp)%=mod;
		}
		for(ll j=5004;j>=a[i];j--) (dp[j]+=dp[j-a[i]])%=mod;
	}
	printf("%lld",ans);
	return 0;
}

//freopen(

/*

AK at 9:10, use 40 min

100+100+100+100=400

dan yuan bie gua fen

D wei shen me zhe me shui


wo yao shang mi huo xin wei da shang

"w",stdin

"r",stdout



da dui pai qv le

*/