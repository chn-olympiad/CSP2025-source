#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int c[N][N];
void zuhe()
{
	c[0][0]=1;
	for(int i=0;i<=5000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=((c[i-1][j])%mod+(c[i-1][j-1])%mod)%mod;
		}
	}
}
int vis[N],ans;
//int dfs(int n,int maxi,int now,int sum){
//	if(now>maxi)
//	{
//		if(sum>a[maxi]*2)
//			return 1;
//		else
//			return 0;	
//	}
//	for(int i=1;i<=maxi;i++)
//	{
//		if(vis[i]==0)
//		{
//			vis[i]=1;
//			ans+=dfs(n,maxi,now+1,sum+a[i]);
//			vis[i]=0;
//		}
//	}
//}
int n,a[N],dp[N][N],sum[N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	zuhe();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
//			dp[i][j]
			if(sum[i-1]>a[j])
				dp[i][a[j]]=c[j-1][i-1];
			else
			{
//				dp[i][a[j]]=max(c[j-1][i-1]-(c[(j-1)-1][i-1]-dp[i][a[j-1]]+1),0);

				dp[i][a[j]]=max(c[j-1][i-1]-(a[j]-sum[i-1]+1),0);	
			}
		}
	}
	

	cout<<ans;
	return 0;
}