#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=19,M=263000;
const ll MOD=998244353;
int n,m,a[N],cnt;
string s;
ll ans,dp[M][N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	if(n>18)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(i&(1<<(j-1))) cnt++;
		}
		for(int j=0;j<=cnt;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if((i&(1<<(k-1)))==0) continue;
				if(s[cnt]=='1'&&(cnt-1)-(j-1)<a[k]) 
				{
					if(j>0) dp[i][j]=(dp[i][j]+dp[i^(1<<(k-1))][j-1])%MOD;
				}
				else dp[i][j]=(dp[i][j]+dp[i^(1<<(k-1))][j])%MOD;
			}
			//printf("%d %d %lld\n",i,j,dp[i][j]);
		}
	}
	for(int i=m;i<=n;i++) ans=(ans+dp[(1<<n)-1][i])%MOD;
	printf("%lld",ans);
	return 0;
}
