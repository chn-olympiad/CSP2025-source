#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001], c[100001];
int dp[201][101][101];
int t, n, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
		if (n <= 200)
		{
			memset(dp, 0, sizeof(dp)); ans = INT_MIN;
			for (int i = 1; i <= n; i++)
				for (int j = n / 2; j >= 0; j--)
					for (int k = n / 2; k >= 0; k--)
						for (int l = n - j - k; l >= 0; l--)
							ans = max(ans, (dp[j][k][l] = max({(j>0)*(dp[j-1][k][l]+a[i]),(k>0)*(dp[j][k-1][l]+b[i]),(l>0)*(dp[j][k][l-1]+c[i])})));
			cout << ans << "\n";
		}
		else
		{
			sort(a + 1, a + n + 1);
			long long sum = 0;
			for (int i = 1; i <= n / 2; i++) sum += a[i];
			cout << sum << "\n";
		}
	}
	return 0;
}