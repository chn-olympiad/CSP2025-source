#include<bits/stdc++.h>
using namespace std;
int n,dp[25][10005],a[5005],maxn;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=(maxn<<1);j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j-a[i]>=0)dp[i][j]++;//=max(1,dp[i-1][j-a[i]]);
		}
	}
	//for(int i=1;i<=n;i++)
	//{
	//	for(int j=0;j<=10;j++)cout<<dp[i][j];
	//	cout<<endl;
	//}
	cout<<dp[n][(maxn<<1)];
	return 0;
}
