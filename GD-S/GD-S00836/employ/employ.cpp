#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,f=1,ans;
int c[510],dp[(1<<18)+10][21];
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	if(n<=18)
	{
		dp[0][0]=1;
		for(int i=0;i<(1<<n)-1;i++)
		{
			int d=__builtin_popcount(i);
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					if((i>>k)&1) continue;
					if(s[d]=='0'||j>=c[k]) dp[i|(1<<k)][j+1]=(dp[i|(1<<k)][j+1]+dp[i][j])%mod;
					else dp[i|(1<<k)][j]=(dp[i|(1<<k)][j]+dp[i][j])%mod;
				}
			}
		}
		for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
		cout<<ans;
	}
	for(int i=0;i<n;i++)
		if(s[i]!='1'||!c[i]) f=0;
	if(n==m)
	{
		if(!f) cout<<0;
		else
		{
			ans=1ll;
			for(int i=1;i<=n;i++) ans=ans*i%mod;
			cout<<ans;
		}
		return 0;
	}
	cout<<0;
}
