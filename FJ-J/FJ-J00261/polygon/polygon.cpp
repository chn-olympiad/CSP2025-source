#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,sum,ans;
int a[N],dp[6][N*N];
int add(int x,int y)
{
	x+=y;
	if(x>=mod) x-=mod;
	return x;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i>=3)
		{
			for(int j=2;j<=4;j++)
				for(int k=a[i]+1;k<=sum;k++)
					ans=add(ans,dp[j][k]);
		}
		for(int k=sum;k>=a[i];k--)
			dp[4][k]=add(dp[4][k],add(dp[3][k-a[i]],dp[4][k-a[i]]));
		for(int j=3;j>=1;j--)
			for(int k=sum;k>=a[i];k--)
				dp[j][k]=add(dp[j][k],dp[j-1][k-a[i]]);
		dp[1][a[i]]=add(dp[1][a[i]],1);
	}
// task2
//	for(int i=1;i<=n;i++)
//	{
//		if(i>=3)
//		{
//			for(int j=3;j<=i;j++)
//				for(int k=1;k<=sum;k++)
//					if(k>a[i]) ans=(ans+dp[j-1][k])%mod;
//		}
//		for(int j=i;j>=1;j--)
//			for(int k=sum;k>=1;k--)
//				if(k-a[i]>=0) dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
//		dp[1][a[i]]++;
//	}

// task 1
//	for(int i=1;i<=n;i++)
//		dp[i][1][a[i]]=1;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=i;j++)
//			for(int k=1;k<=sum;k++)
//			{
//				dp[i][j][k]+=dp[i-1][j][k];
//				if(k-a[i]>=0) dp[i][j][k]+=dp[i-1][j-1][k-a[i]];
//			}
//	for(int i=3;i<=n;i++)
//		for(int j=3;j<=i;j++)
//			for(int k=1;k<=sum;k++)
//				if(k>a[i]) ans=(ans+dp[i-1][j-1][k]);
	printf("%d",ans);
	return 0;
}

/*

5
1 2 3 4 5 

*/
