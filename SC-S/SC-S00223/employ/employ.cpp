#include<bits/stdc++.h>
#define ll long long
#define INF 214748364719260817ll
using namespace std;
const int MOD=998244353;
ll n,m;
string s;
ll c[505];
ll mol(ll x)
{
	return x>=MOD?x-MOD:x;
}
namespace force
{
	ll dp[1<<18][19];
	void solve()
	{
		dp[0][0]=1;
		for(ll i=0;i<(1<<n);++i)
			for(ll j=0;j<n;++j)
				if(((i>>j)&1)==0)
				{
					ll ns=s[__builtin_popcountll(i)+1]-'0';
					if(ns==0)
					{
						for(ll k=0;k<=__builtin_popcountll(i);++k)
						dp[i^(1<<j)][k+1]=mol(dp[i^(1<<j)][k+1]+dp[i][k]);
					}
					else
					{
						for(ll k=0;k<=__builtin_popcountll(i);++k)
						{
							if(c[j+1]<=k)dp[i^(1<<j)][k+1]=mol(dp[i^(1<<j)][k+1]+dp[i][k]);
							else dp[i^(1<<j)][k]=mol(dp[i^(1<<j)][k]+dp[i][k]);
						}
					}
				}
		ll res=0;
		for(ll i=0;i<=n-m;++i)res=mol(res+dp[(1<<n)-1][i]);
		cout<<res;
	}
}
ll sum[505],f[505];
int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	bool i0=1;
	ll os=0;
	f[0]=1;
	for(ll i=1;i<=n;++i)cin>>c[i],os+=(s[i]-'0'),i0&=(c[i]&&(s[i]-'0')),++sum[c[i]],f[i]=f[i-1]*i%MOD;
	for(ll i=1;i<=n;++i)sum[i]+=sum[i-1];
	if(n<=18)force::solve();
	else if(n==m)
	{
		if(i0)
		cout<<f[n];
		else cout<<0;
	}
	else if(m==1)
	{
		ll res=f[n];
		vector<ll>where;
		for(ll i=1;i<=n;++i)
			if(s[i]-'0')
			where.emplace_back(i);
		ll s=1;
		for(ll i=0;i<where.size();++i)s=s*max(0ll,sum[where[i]-1]-i)%MOD;
		s=s*f[n-where.size()]%MOD;
		cout<<mol(res-s+MOD);
	}
	else if(os<=18)
	{
		
	}
}//m=1,n 是送 
//问题在于找到一个合适的转移顺序