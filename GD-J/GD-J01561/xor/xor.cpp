#include<bits/stdc++.h>
using namespace std;
long long n,k;
struct node
{
	long long num,x;
}dp[50005][50005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> dp[i][i].num;
	for(int i = 1;i <= n;i++)
	{
		int tf = 0;
		for(int j = i;j <= n;j++)
		{
			if(j == i)
				dp[i][j].x = dp[i-1][j-1].x;
			dp[i][j].num = ((dp[i][j-1].num) ^ (dp[j][j].num));
			if(dp[i][j].num == k && tf == 0)
			{
				dp[i][j].x++;
				tf = 1;
			}
			dp[i][j].x = max(dp[i][j].x + dp[i][j-1].x,dp[i-1][j].x);
		}
	}
	cout << dp[n][n].x;
	return 0;
}
