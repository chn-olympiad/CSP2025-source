#include <bits/stdc++.h>
using namespace std;

int t; long long a[100005][4], dp[205][205][205];
vector <int> v;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		memset(dp, 0, sizeof dp);
		long long n, ans = -1e18; bool vis = true;
		cin >> n;
		for (int i = 1; i <= n; i ++) 
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0) vis = false;
		}
		if (vis)
		{
			ans = 0;
			for (int i = 1; i <= n; i ++) v.push_back(a[i][1]);
			sort(v.begin(), v.end(), cmp);
			for (int i = 0; i < n / 2; i ++) ans += v[i];
			cout << ans << endl;
			return 0;
		}
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 0; j <= i; j ++)
				for (int k = 0; k <= i - j; k ++)
				{
					int l = i - j - k;
					if (j <= n / 2 && k <= n / 2 && l <= n / 2) 
					{
						if (j - 1 >= 0) dp[j][k][l] = max(dp[j][k][l], dp[j - 1][k][l] + a[i][1]);
						if (k - 1 >= 0) dp[j][k][l] = max(dp[j][k][l], dp[j][k - 1][l] + a[i][2]);
						if (l - 1 >= 0) dp[j][k][l] = max(dp[j][k][l], dp[j][k][l - 1] + a[i][3]);
					}

				}
		}
		for (int i = 0; i <= n; i ++)
			for (int j = 0; j <= n - i; j ++)
			{
				int k = n - i - j;
				if (i <= n / 2 && j <= n / 2 && k <= n / 2)
					ans = max(ans, dp[i][j][k]);
			}
		cout << ans << endl;
	}
}
