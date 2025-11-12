#include<bits/stdc++.h>
typedef long long ll;
const ll maxn=5e3+10,mod=998244353;
using namespace std;
ll fact[maxn],inv[maxn];
ll owo[maxn],dp[maxn][maxn],num[maxn];
inline ll read(){
	ll ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline ll A(ll n,ll k) {return (fact[n]*inv[n-k])%mod;}
inline ll C(ll n,ll k) {return (A(n,k)*inv[k])%mod;}
inline ll fmul(ll a,ll n)
{
	ll ret=1;
	while (n)
	{
		if (n&1) 
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return ret;
}
inline void _init(ll M)
{
	fact[0]=1;
	for (ll i=1;i<=M;++i)
		fact[i]=(fact[i-1]*i)%mod;
	
	inv[M]=fmul(fact[M],mod-2);
	
	for (ll i=M-1;i>=0;--i)
		inv[i]=(inv[i+1]*(i+1))%mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ll n=read(),M=0;
	for (ll i=1;i<=n;++i)
		owo[i]=read(),M=max(M,owo[i]);
	
	sort(owo+1,owo+n+1);
	
	_init(5000);

	//dp[i][j]表示到第i个数之和为j的方案数 
	//dp[2][owo[1]+owo[2]]=1
	//dp[i][j]=dp[i-1][j]+dp[i-1][j-owo[i]]+num[j-owo[i]]
	//ans+=Σ(j=2;i-1)C(i-1,j) - Σ(j=1;owo[i])dp[i-1][j] 
	
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
	dp[2][owo[1]+owo[2]]=1;
	num[owo[1]]++,num[owo[2]]++;
	
	ll ans=0;
	for (ll i=3;i<=n;++i)
	{
		for (ll j=2;j<=i-1;++j)
			ans=(ans+C(i-1,j))%mod;
		for (ll j=0;j<=M;++j)
		{
			if (j<=owo[i])
				ans=(ans+mod-dp[i-1][j])%mod;
			dp[i][j]=dp[i-1][j];
			if (j-owo[i]>0)
				dp[i][j]=(dp[i][j]+dp[i-1][j-owo[i]]+num[j-owo[i]])%mod;
		}
		num[owo[i]]++;
	}
	printf("%lld ",ans);
} 
