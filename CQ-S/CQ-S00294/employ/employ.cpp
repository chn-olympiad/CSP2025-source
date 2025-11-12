#include <bits/stdc++.h>
#define int long long
using namespace std;
bool st;
const int N = 505,mod = 998244353;
int n,m,a[N];
string s;
namespace sub1{
	int f[1<<18][20];
	inline void main()
	{
		f[0][0] = 1;
		for(int z = 1;z<(1<<n);z++)
		{
			int cnt = __builtin_popcount(z);
			for(int i = 1;i<=n;i++)
				if((z>>i-1)&1)
				{
					for(int j = 0;j<=n;j++)
					{
						if(s[cnt]=='0'||a[i]<=j) (f[z][j+1]+=f[z^(1<<i-1)][j])%=mod; 
						else (f[z][j]+=f[z^(1<<i-1)][j])%=mod;
					}
				}
		}
		int ans = 0;
		for(int i = 0;i<=n-m;i++) (ans+=f[(1<<n)-1][i])%=mod; 
		cout<<ans;
	}
}
namespace sub2{
	const int N = 105;
	int ton[N],f[N][N][N],fac[N],c[N][N],w[N][N],pre[N];
	inline void main()
	{
		for(int i = 1;i<=n;i++) ton[a[i]]++;
		pre[0] = ton[0];
		for(int i = 1;i<=n;i++) pre[i] = pre[i-1]+ton[i];
		fac[0] = 1;
		for(int i = 1;i<=n;i++) fac[i] = fac[i-1]*i%mod;
		c[0][0] = 1;
		for(int i = 1;i<=n;i++)
		{
			c[i][0] = 1;
			for(int j = 1;j<=i;j++)
				c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
		}
		for(int i = 0;i<=n;i++)
		{
			int tmp = 1;
			for(int j = 0;j<=i;j++)
			{
				w[i][j] = tmp;
				tmp = tmp*(i-j)%mod;
			}
		}
		f[0][0][0] = 1;
		int cnt = 0;
		for(int i = 0;i<n;i++)
			for(int j = 0;j<=n;j++)
				for(int k = 0;k<=n;k++)
				{
//					if(f[i][j][k])
//					{
//						cout<<i<<' '<<j<<' '<<k<<":"<<f[i][j][k]<<'\n'; 
//					}
					if(s[i+1]=='1')
					{
						(f[i+1][j][k]+=f[i][j][k])%=mod; 
						for(int x = 0;x<=i-k;x++)
						{
							(f[i+1][j+1][k+x+1]+=f[i][j][k]*c[i-k][x]%mod*w[ton[j+1]][x]%mod*(pre[j]-k))%=mod;
						}
					}
					else
					{
						cnt++;
						for(int x = 0;x<=i-k;x++)
						{
							(f[i+1][j+1][k+x]+=f[i][j][k]*c[i-k][x]%mod*w[ton[j+1]][x]%mod)%=mod;
							(f[i+1][j+1][k+x+1]+=f[i][j][k]*c[i-k][x]%mod*w[ton[j+1]][x]%mod*(pre[j]-k))%=mod;
						}
					}
				}
		int ans = 0;
		for(int i = 0;i<=n-m;i++)
		{
			for(int j = pre[i];j<=pre[i];j++)
				(ans+=f[n][i][j]*fac[n-j])%=mod;
		}
		cout<<ans<<'\n';
	}
}
bool en;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cerr<<(&st-&en)/1024/1024<<"MB\n";
	cin>>n>>m>>s,s = ' '+s;
	for(int i = 1;i<=n;i++)
		cin>>a[i];
	if(n<=18) sub1::main();
	else sub2::main();
	return 0;
}

