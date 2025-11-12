#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define lxl long long
#define INF 1000000000
namespace lzz
{
	char s[N];
	int n,m,c[N],t[N];
	int f[2][(1<<19)][19];
	void init(int p)
	{
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<=n;j++)f[p&1][i][j]=0;
		}
	}
	int inv[N];
	const int mod=998244353;
	int main()
	{
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		cin>>n>>m>>(s+1);
		for(int i=1;i<=n;i++)cin>>c[i];
		if(n<=18)
		{
			f[0][0][0]=1;
			for(int i=1;i<=n;i++)
			{
				init(i);
				for(int j=0;j<(1<<n);j++)
				{
					for(int k=0;k<=n;k++)
					{
						if(!f[(i-1)&1][j][k])continue;
						for(int p=0;p<n;p++)
						{
							if(!((j>>p)&1))
							{
								f[i&1][j+(1<<p)][k+(c[p+1]>(i-1-k))*(s[i]=='1')]=(f[i&1][j+(1<<p)][k+(c[p+1]>(i-1-k))*(s[i]=='1')]+f[(i-1)&1][j][k])%mod;
							}
						}
						
					}
				}
			}
			int ans=0;
			for(int i=m;i<=n;i++)ans=(ans+f[n&1][(1<<n)-1][i])%mod;
			cout<<ans<<'\n';
			return 0;
		}
		if(m==1)
		{
			inv[0]=1; for(int i=1;i<=n;i++)inv[i]=1ll*inv[i-1]*i%mod;
			for(int i=1;i<=n;i++)t[c[i]]++;
			for(int i=1;i<=n;i++)t[i]+=t[i-1];
			int ans=1,num=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='1')ans=1ll*ans*max(0,t[i-1]-num)%mod,num++;
			}cout<<(inv[n]-1ll*ans*inv[n-num]%mod+mod)%mod;
			return 0;
		}

		return 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	return lzz::main();
}

