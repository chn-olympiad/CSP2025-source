#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		bool flag2 = true, flag3 = true;
		int n;
		cin >> n;
		int a[100005][4] = {};
		int dp[5005][4][5005] = {};
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2] != 0)
			{
				flag2 = false;
			}
			if(a[i][3] != 0)
			{
				flag3 = false;
			}
		}
		if(flag2 && flag3)
		{
			int a1[100005] = {};
			for(int i = 1; i <= n; i++)
			{
				a1[i] = a[i][1];
			}
			sort(a1 + 1, a1 + n + 1, cmp);
			int sum = 0;
			for(int i = 1; i <= n / 2; i++)
			{
				sum += a1[i];
			}
			cout << sum << endl;
			return 0;
		}
		/**dp[1][1][1] = a[1][1];
		dp[1][2][1] = a[1][2];
		dp[1][3][1] = a[1][3];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 3; j++)
			{
				for(int k = 1; k <= n / 2; k++)
				{
					dp[i][j][k] = max(dp[i - 1][j][k - 1] + a[i][j], dp[i - 1][j][k]);
				}
			}
		}
		int sum = 0;
		for(int j = 1; j <= 3; j++)
		{
			sum += dp[n][j][n / 2];
		}
		cout << sum << endl;
		**/
	}
	return 0;
}
