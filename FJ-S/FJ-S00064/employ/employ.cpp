#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e2+10;
const int maxm=1e6+10;
const int mod=998244353;
int n,m,c[maxn],dp[(1<<18)][20],ans,sum[maxn];
string ss;
inline void get(int &x,int y){x=(x+y)%mod;}
signed main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> ss;
	ss=" "+ss;
	for (int i=1;i<=n;i++) cin >> c[i],sum[c[i]]++;
	for (int i=1;i<=n;i++) sum[i]+=sum[i-1];
	if (m==n)
	{
		int fl=0;
		for (int i=1;i<=n;i++) if (ss[i]=='1') fl=1;
		for (int i=1;i<=n;i++) if (c[i]==0) fl=1;
		if (fl) cout << 0;
		else
		{
			int ans=1;
			for (int i=1;i<=n;i++) ans=ans*i%mod;
			cout << ans;
		}
	}
	else if (m==1)
	{
		int ans=1;
		for (int i=1;i<=n;i++) ans=ans*i%mod;
		int res=1,cnt=0,t=0;
		for (int i=1;i<=n;i++)
		{
			if (ss[i]=='1') cnt++;
			else
			{
				res=res*max(0ll,sum[i-1]-t)%mod;
				t++;
			}
		}
		for (int i=1;i<=cnt;i++) res=res*i%mod;
		cout << (ans-res+mod)%mod;
	}
	else
	{
		dp[0][0]=1;
		for (int s=1;s<(1<<n);s++)
		{
			int cnt=0;
			for (int i=1;i<=n;i++) if ((s>>i-1)&1) cnt++;
			for (int i=0;i<cnt;i++) for (int j=1;j<=n;j++) if ((s>>j-1)&1) get(dp[s][i+(ss[cnt]=='0'||c[j]<=i)],dp[s^(1<<j-1)][i]);
		}
		for (int i=0;i<=n-m;i++) get(ans,dp[(1<<n)-1][i]);
		cout << ans;
	}
	return 0;
}
/*
10 1
1101101101
0 0 1 1 1 2 2 3 4 5
*/
