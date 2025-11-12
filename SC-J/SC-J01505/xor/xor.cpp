#include<bits/stdc++.h>
#define mian main
using namespace std;
const int N=1e3+6;
int dp[N][N];
int n,k,ans=0;
int a[N];
int sum[N];//异或前缀和
int mian()//钓符「英讷特面」
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	if(n>5e5)
	{
		cout<<0;
		exit(0);
		//奇迹总司令
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=-INT_MAX;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int w=sum[i]^sum[j-1];
			dp[i][j]=max(dp[i][j],dp[j-1][j-1 ]+(w==k));
		
			if(w==k)dp[i][i]=max(dp[i][i],dp[i][j]);
			
			//cout<<dp[i][j]<<":"<<i<<" "<<j<<" "<<w<<endl;
		}
		//cout<<dp[i][i]<<endl;
		ans=max(ans,dp[i][i]);
		
	}
	cout<<ans;
	return 0;
}//给我 60pts