#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N = 1e5+5;
int a[N][5];
int dp[205][105][105];
int n;
int solveA()
{
	priority_queue<int> q;
	int i, res = 0;
	for(i = 1; i <= n; i++)
	{
		q.push(a[i][1]);
	}
	for(i = 1; i <= n / 2; i++)
	{
		res += q.top();
		q.pop();
	}
	return res;
}
int solveB()
{
	int i, res = 0;
	for(i = 1; i <= n; i++)
		res += a[i][2], a[i][1] -= a[i][2];
	return res + solveA();
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t, i, j, k, ans;
	bool c, d;
	cin >> t;
	while(t--)
	{
		cin >> n;
		c = d = 1;
		for(i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] != 0)
				c = 0;
			if(a[i][3] != 0)
				d = 0;
		}
		if(c || d)
		{
			if(c)
				cout << solveA() << endl;
			else
				cout << solveB() << endl;
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[1][1][0] = a[1][1];
		dp[1][0][1] = a[1][2];
		dp[1][0][0] = a[1][3];
		for(i = 2; i <= n; i++)
		{
			for(j = 0; j <= min(i, n / 2); j++)
			{
				for(k = 0; k <= min(i - j, n / 2); k++)
				{
					dp[i][j][k] = dp[i-1][j][k] + a[i][3];
					if(j >= 1)
						dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[i][1]);
					if(k >= 1)
						dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + a[i][2]);
//					cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
				}
			}
		}
		ans = 0;
		for(i = 0; i <= n / 2; i++)
		{
			for(j = 0; j <= min(n - i, n / 2); j++)
			{
				if(n - i - j <= n / 2)
				{
					ans = max(ans, dp[n][i][j]);
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
