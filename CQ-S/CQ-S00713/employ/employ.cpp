#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&-x)
#define endl '\n'

namespace satsujinki{
const int mod=998244353;
const int maxn=510;
int n,m,s[maxn],c[maxn];
int cnt[maxn];
int jc[maxn],ijc[maxn];
int dp[(1<<18)+10][19];

int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int C(int n,int m)
{
	if(n<m||m<0)
	{
		return 0;
	}
	return jc[n]*ijc[n-m]%mod*ijc[m]%mod;
}

void MAIN()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	jc[0]=1;
	ijc[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		cnt[c[i]]++;
		jc[i]=jc[i-1]*i%mod;
		ijc[i]=qpow(jc[i],mod-2);
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		int p=__builtin_popcount(i);
		for(int j=1;j<=n;j++)
		{
			if(((i>>(j-1))&1)^1)
			{
				for(int k=0;k<n;k++)
				{
					if(c[j]>k&&s[p+1])
					{
						dp[i|(1<<(j-1))][k]=(dp[i|(1<<(j-1))][k]+dp[i][k])%mod;
					}
					else
					{
						dp[i|(1<<(j-1))][k+1]=(dp[i|(1<<(j-1))][k+1]+dp[i][k])%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++)
	{
		ans=(ans+dp[(1<<n)-1][i])%mod;
	}
	cout<<ans<<endl;
}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	satsujinki::MAIN();
//while(1);
	return 0;
}
/*
time:1.0 S
memory:512 MiB
real:

能不能AK CSP-S就看这道恶心计数题了（我最不擅长的）!!! 
no，不能AK了 

显然不能直接做，考虑转换问题 
猜测应该是dp，状态i,j表示第i天结束，j个人未通过 
枚举当前可选人数k 

*/
