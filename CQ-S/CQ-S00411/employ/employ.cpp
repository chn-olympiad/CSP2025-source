#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans=0,now=0,c[505],dp[(1<<18)][20];
bool pd=1;
string s;
struct node
{
	int u,zt;
}p[(1<<18)];
bool cmp(node x,node y)
{
	return x.u<y.u;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	for(int zt=0;zt<(1<<n);zt++)
	{
		p[zt].zt=zt;
		p[zt].u=0;
		for(int j=0;j<n;j++)
		{
			if((zt&(1<<j))!=0)
			{
				p[zt].u++;
			}
		}
	}
	sort(p,p+(1<<n),cmp);
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		while(p[now].u<=i)
		{
			int zt=p[now].zt;
			for(int k=0;k<n;k++)
			{
				if((zt&(1<<k))==0)
				{
					for(int j=0;j<=i;j++)
					{
						if(s[i]=='0'||i-j>=c[k])
						{
							dp[zt|(1<<k)][j]=(dp[zt|(1<<k)][j]+dp[zt][j])%mod;
						}
						else
						{
							dp[zt|(1<<k)][j+1]=(dp[zt|(1<<k)][j+1]+dp[zt][j])%mod;
						}
					}
				}
			}
			now++;
		}
	}
	for(int i=m;i<=n;i++)
	{
		ans=(ans+dp[(1<<n)-1][i])%mod;
	}
	cout<<ans;
	return 0;
}
