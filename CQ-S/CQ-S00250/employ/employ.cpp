#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long mod=998244353;
long long n,m,ans=0,p[505],a[505],dp[(1<<20)+5][20];
bool vis[505];
string s;
long long lowbit(long long x)
{
	return x&-x;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dp[0][0]=1;
	cin>>n>>m>>s;
	for(long long i=0;i<=n-1;i++)
	{
		cin>>p[i];
	}
	for(long long i=0;i<=n-1;i++)
	{
		a[i]=(s[i]=='1'); 
	}
	for(long long i=0;i<=(1<<n)-1;i++)
	{
		long long cnt=__builtin_popcount(i);
		for(long long j=0;j<=min(cnt,m);j++)
		{
			for(long long k=((1<<n)-1)^i;k>=1;k-=lowbit(k))
			{
				long long t1=i|lowbit(k),t2=min(m,j+(a[cnt]&&cnt-j<p[__lg(lowbit(k))]));
				dp[t1][t2]=(dp[t1][t2]+dp[i][j])%mod;
			}
		}
	}
	cout<<dp[(1<<n)-1][m]<<endl;
	return 0;
}
