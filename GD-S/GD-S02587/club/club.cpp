#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N][4], res = 0, n, m, rst[N][4][4], e[N][4];

void dfs(int pos, int x, int y, int z, int sum)
{
	if (pos > n)
	{
		res = max(sum, res);
		return;
	}
	
	if (x > 0)
	{
		dfs(pos + 1, x - 1, y, z, sum + e[pos][1]);
	}
	
	if (y > 0)
	{
		dfs(pos + 1, x, y - 1, z, sum + e[pos][2]);
	}
	
	if (z > 0)
	{
		dfs(pos + 1, x, y, z - 1, sum + e[pos][3]);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	
	while (T--)
	{
		cin >> n;
		m = n / 2;
		res = 0;
		
		for (int i = 1; i <= n; i++)
		{
			cin >> e[i][1] >> e[i][2] >> e[i][3];
		}
		
		if (n <= 10)
		{
			dfs(1, m, m, m, 0);
			cout << res << endl;
		}
		else
		{
			memset(dp, 0, sizeof(dp));
			memset(rst, 0, sizeof(rst));
			dp[1][1] = e[1][1];
			dp[1][2] = e[1][2];
			dp[1][3] = e[1][3];
			
			rst[1][1][1] = m - 1;
			rst[1][1][2] = rst[1][1][3] = m;
			
			rst[1][2][2] = m - 1;
			rst[1][2][1] = rst[1][2][3] = m;
			
			rst[1][3][3] = m - 1;
			rst[1][3][1] = rst[1][3][2] = m;	
				
			for (int i = 2; i <= n; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					int mxpos;
					bool f = true;
					
					for (int k = 1; k <= 3; k++)
					{
						if (j == k && rst[i - 1][k][j] == 0)
						{
							continue;
						}
						
						if (f || dp[i - 1][k] > dp[i - 1][mxpos])
						{
							mxpos = k;
							f = false;
						}
					}
					
					dp[i][j] = dp[i - 1][mxpos] + e[i][j];
					rst[i][j][j] = rst[i - 1][mxpos][j] - 1;
				}
			}
			
			res = max(dp[n][1], max(dp[n][2], dp[n][3]));
			cout << res << endl;
		}
	}
	
	return 0;
}

