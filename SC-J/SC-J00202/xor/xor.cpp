#include<iostream>
using namespace std;
#define int long long
int dp[5005][5005],a[100005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int flagb=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=0 || a[i]!=1) flagb=1;
		if(a[i]==k) dp[i][i]++;
	}
	for (int len=2;len<=n;len++)
	{
		for (int s=1;s<=n-len+1;s++)
		{
			int e=s+len-1;
			int ans=a[s];
			for (int j=s;j<=e-1;j++)
			{
				dp[s][e]=max(dp[s][e],dp[s][j]+dp[j+1][e]);
				if (j!=s) ans=ans^a[j];
			}
			ans=ans^a[e];
			int qqq=1;
			if (ans==k) dp[s][e]=max(dp[s][e],qqq);
			
		 } 
	}
	cout<<dp[1][n];
	return 0;
}