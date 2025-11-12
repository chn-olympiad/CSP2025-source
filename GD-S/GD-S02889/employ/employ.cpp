#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const long long maxn=505;
long long n,m;
long long s[maxn];
long long c[maxn];
long long dp[(1<<19)+1][20];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char in;
	for(long long i=1;i<=n;i++)
	{
		cin>>in;
		s[i]=in-'0';
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==n)
	{
		for(long long i=1;i<=n;i++)
		{
			if(s[i]==0||c[i]==0)
			{
				cout<<0<<'\n';
				return 0;
			}
		}
		long long ans=1;
		for(long long i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans<<'\n';
		return 0;
	}
	long long sta=(1<<n)-1;
	dp[0][0]=1;
	for(long long i=0;i<=sta;i++)
	{
		long long w=0,ii=i;
		while(ii)
		{
			if(ii&1)
			{
				w++;
			}ii/=2;
		}
		for(long long j=0;j<=w;j++)
		{
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
			for(long long k=1;k<=n;k++)
			{
				if((1<<(k-1))&i)
				{
					continue;
				}
//				cout<<((1<<(k-1))|i)<<' ';
				if(w-j>=c[k]||s[w+1]==0)
				{
					dp[(1<<(k-1))|i][j]=(dp[i][j]+dp[(1<<(k-1))|i][j])%mod;
//					cout<<j<<'\n';
				}
				else
				{
					dp[(1<<(k-1))|i][j+1]=(dp[i][j]+dp[(1<<(k-1))|i][j+1])%mod;
//					cout<<j+1<<'\n';
				}
			}
		}
	}
	long long ans=0;
	for(long long i=m;i<=n;i++)
	{
		ans+=dp[sta][i];
	}
	cout<<ans<<'\n';
}
