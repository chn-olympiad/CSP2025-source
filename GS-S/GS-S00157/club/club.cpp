#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t, n;
int a[100003], b[100003], c[100003]; //ÂúÒâ¶È
int d[100003][5];
int sum;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int dp[50003] = {0};
		cin >> n;
		int m = n/2;
		int k = n;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j] >> b[j] >> c[j];
			d[j][1] = a[j];
			d[j][2] = b[j];
			d[j][3] = c[j];
			sort (d[j]+1, d[j]+1+3);
			dp[j] = max(a[j], max(b[j], c[j]));
		}
		for (int j = n - 1; j >= 1; j--)
		{
			int x[100003] = {0};
			x[n] = 3;
			if (n <= 0)
			{
				break;
			}
			if (x[j+1] = 3)
			{
				if (dp[j+1] - d[j+1][3] + d[j+1][2] + dp[j] > dp[j+1] + d[j][2])
				{
					dp[j] = dp[j+1] - d[j+1][3] + d[j+1][2] + d[j][3];
					m--;
					x[j] = 3;
					k--;
				}
				else if (dp[j+1] - d[j+1][3] + d[j+1][2] + d[j][3] == dp[j+1])
				{
					dp[j] = dp[j+1] + d[j][3];
					m--;
					x[j] = 1;
				}
				else
				{
					dp[j] = dp[j+1] + d[j][3];
					x[j] = 3;
					k--;
				}
			}
			else
			{
				if (m <= 0)
				{
					break;
				}
				if (dp[j+1] >= dp[j])
				{
					dp[j] = dp[j+1] + d[j][3];
					k--;
				}
				else
				{
					dp[j] = d[j][2];
					m--;
					k--;
				}
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}
