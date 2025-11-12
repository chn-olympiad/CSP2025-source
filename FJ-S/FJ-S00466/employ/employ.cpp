#include<bits/stdc++.h>
#define mod 998244353
#define N 505
using namespace std;
int n,m,ans,a[N],f[1<<20][20];
char c[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	f[0][0]=1;
	for(int s=0;s<(1<<n)-1;s++)
	{
		int cnt=0;
		for(int i=0;i<n;i++) if(s&(1<<i)) cnt++;
		for(int i=1;i<=n;i++)
		{
			if(s&(1<<i-1)) continue;
			for(int j=0;j<=cnt;j++)
			{
				if(j>=a[i]||c[cnt+1]=='0')
				{
					f[s|(1<<i-1)][j+1]=(f[s|(1<<i-1)][j+1]+f[s][j])%mod;
				}
				else
				{
					f[s|(1<<i-1)][j]=(f[s|(1<<i-1)][j]+f[s][j])%mod;
				}
			}
		}
	}
	for(int i=0;i<=n-m;i++) ans=(ans+f[(1<<n)-1][i])%mod;
	cout<<ans;
	return 0;
}
