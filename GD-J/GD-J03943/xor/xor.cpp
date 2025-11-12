#include <bits/stdc++.h>
using namespace std;
int n,k;
int sum[500005];
int dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		int x;
		cin>>x;
		sum[i] = (sum[i-1]^x);
	}
	for(int i = 1;i<=n;i++)
	{
		dp[i] = dp[i-1];
		for(int j = 1;j<=i;j++)
		{
			if((sum[i]^sum[i-j]) == k)
			{
				dp[i] = max(dp[i],dp[i-j]+1);
				break;
			} 
		}
	}
	cout<<dp[n];
	return 0;
}
/*
4 2
2 1 0 3
#Shang4Shan3Ruo6Shui4
*/
