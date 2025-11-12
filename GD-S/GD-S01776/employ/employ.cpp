#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;

int n,m,s[N],c[N];
namespace Sol1
{
	const int N=3e5+10;
	int f[N][20];
	void solve()
	{
		f[0][0]=1;
		for(int S=0;S<(1<<n);S++)
		{
			int t=__builtin_popcount(S);
			for(int i=1;i<=n;i++)
			{
				if(S&(1<<i-1)) continue;
				for(int j=0;j<=t;j++)
				{
					if(c[i]<=t-j||!s[t+1]) (f[S|(1<<i-1)][j]+=f[S][j])%=mod;
					else (f[S|(1<<i-1)][j+1]+=f[S][j])%=mod;
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++) (ans+=f[(1<<n)-1][i])%=mod;
		cout<<ans<<endl;
	}
};

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {char t;cin>>t;s[i]=t-'0';}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=20) Sol1::solve();
	return 0;
}



