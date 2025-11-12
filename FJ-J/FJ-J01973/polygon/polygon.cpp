#include<bits/stdc++.h>
using namespace std;

int n,a[5005],sum[5005],v[5005],anss,dp[5005][5005];

long long c(int n,int m)
{
	long long aa=n,b=m,c=n-m;
	for(int i=n-1;i>=1;i--) aa=(aa*i)%998244353;
	for(int i=m-1;i>=1;i--) b=(b*i)%998244353;
	for(int i=n-m-1;i>=1;i--) c=(c*i)%998244353;
	if(c==0) c=1;
	return aa/(b*c);
}

void dfs(int nw,int s,int mx)
{
	if(nw==n+1)
	{
		if(s>mx*2) anss++;
		return ;
	}
	dfs(nw+1,s,mx);
	dfs(nw+1,s+a[nw],max(mx,a[nw]));
	return ;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	while(a[n]*2>sum[n]) n--;
	if(n<=3)
	{
		if(n<3) cout<<0;
		else if(a[n]*2<sum[n]) cout<<1;
			 else cout<<0;
		return 0;
	}
	if(a[n]<=1)
	{
		long long ans=0;
		for(int i=3;i<=n;i++)
			ans=(ans+c(n,i))%998244353;
		cout<<ans;
		return 0;
	}
	if(n<=200) 
	{
		dfs(1,0,-1);
		cout<<anss%998244353-1;
		return 0;
	}
	for(int i=3;i<=n;i++) if(a[i+2]*2<a[i]+a[i+1]+a[i+2]) dp[i][3]=dp[i-1][3]+1;
	int sss=-1;
	for(int i=1;i<=n;i++)
		for(int j=4;j<=i;j++)
		{
			if(a[i]*2<sum[i]) dp[i][j]+=dp[i-1][j-1];
			else dp[i][j]=dp[i-1][j];
			sss=max(sss,dp[i][j]);
		}
	for(int i=4;i<=n;i++) dp[n][i]+=dp[n][i-1];
	cout<<dp[n][n];
	
	return 0;
}
