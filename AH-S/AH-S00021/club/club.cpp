#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
struct point
{
	int c[4];
} l[N];
bitset<N> vis;
long long dp[501][251][251];
void solve()
{
	memset(dp, 0, sizeof(dp));
	long long ans = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &l[i].c[1], &l[i].c[2], &l[i].c[3]);
	if (n <= 500)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= n / 2; ++j)
				for (int k = 0; k <= n / 2; ++k)
				{
					if (j >= 1 && i - j - k <= n / 2)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + l[i].c[1]);
					if (k >= 1 && i - j - k <= n / 2)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + l[i].c[2]);
					if (i - j - k >= 1 && i - j - k <= n / 2)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + l[i].c[3]);
					if (i == n && i - j - k <= n / 2)
					{
						ans = max(ans, dp[i][j][k]);
					}
				}
		printf("%lld\n", ans);
		return;
	}
	else
	{	
		priority_queue<int> pq;
		for (int i = 1; i <= n; ++i)
			pq.push(l[i.c[1]]);
		for (int i = 1; i <= n / 2; ++i)
			ans _+= pq.top(), pq.pop();
		printf("%lld\n", ans);
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
