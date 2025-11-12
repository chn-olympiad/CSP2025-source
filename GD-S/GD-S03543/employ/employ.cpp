#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int dp[300005][20];
char s[30];
int c[30];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		int num=0;
		for(int j=1;j<=n;j++)
		{
			if((1<<(j-1))&i) num++;
		}
		for(int j=1;j<=n;j++)
		{
			if((1<<(j-1))&i)
			{
				for(int k=0;k<=num;k++)
				{
					if(s[num]=='0')
					{
						if(k)
						{
							dp[i][k]+=dp[i-(1<<(j-1))][k-1];
							dp[i][k]%=mod;
						}
					}
					else
					{
						if(k)
						{
							if(c[j]<=k-1)
							{
								dp[i][k]+=dp[i-(1<<(j-1))][k-1];
								dp[i][k]%=mod;
							}
						}
						if(c[j]>k)
						{
							dp[i][k]+=dp[i-(1<<(j-1))][k];
							dp[i][k]%=mod;
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) (ans+=dp[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}
