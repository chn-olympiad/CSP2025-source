#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,cnt[N],a[N],val[N],sum[N],dp[N][N],ans,c[N][N],res[N],jc[N],p[N];
string s;
bool pd()
{
	for(int i=1;i<=n;i++)if(s[i]=='0')return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s,s=' '+s;
	for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+(s[i]=='0');
	for(int i=1,x;i<=n;i++)cin>>x,val[i]=x,a[x]++;
	sum[0]=a[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	if(n<=10)
	{
		for(int i=1;i<=n;i++)p[i]=i;
		for(int i=1;i<=jc[n];i++)
		{
			int Cnt=0;
			for(int j=1;j<=n;j++)if(s[j]=='0'||Cnt>=val[p[j]])Cnt++;
			if(n-Cnt>=m)ans++;
			next_permutation(p+1,p+n+1);
		}
		cout<<ans;
		return 0;
	}
	if(pd())
	{
		dp[0][a[0]]=jc[a[0]];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)if(dp[i-1][j])
			{
				if(j<i)
				{
					dp[i][j]=(dp[i][j]+1ll*dp[i-1][j]*c[sum[i]][sum[i-1]]%mod*jc[a[i]])%mod;
					continue;
				}
				for(int k=0;k<=a[i];k++)
				{
					int x=sum[i-1]-j+i-1;
					dp[i][j+a[i]-k]=(dp[i][j+a[i]-k]+1ll*dp[i-1][j]*c[x+k][k]%mod*c[sum[i]-(x+k)-1][a[i]-k]%mod*jc[a[i]])%mod;
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n-m;i++)ans=(ans+dp[n][i])%mod;
		cout<<ans;
		return 0;
	}
	if(m==n)return cout<<0,0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')for(int j=1;j<=i;j++)dp[i][j]=dp[i-1][j-1];
		else{
			for(int j=0;j<=i;j++)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
				if(j)dp[i][j]=(dp[i][j]+1ll*dp[i-1][j-1]*(sum[j-1]-(j-1)+cnt[i]))%mod;
			}
		}
	}
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod; 
	for(int i=n;i>=cnt[n];i--)
	{
		res[i]=1ll*dp[n][i]*jc[n-i+cnt[n]]%mod;
		for(int j=i+1;j<=n;j++)res[i]=(res[i]-1ll*res[j]*c[j-cnt[n]][i-cnt[n]])%mod;
	}
	for(int i=0;i<=n-m;i++)ans=(ans+res[i])%mod;
	cout<<(ans+mod)%mod;
	return 0;
}

