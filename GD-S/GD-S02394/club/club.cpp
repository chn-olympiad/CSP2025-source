#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6, M = 206;
struct node {int id, diff;} d[N];
int T, n, a[N], b[N], c[N], dp[M][M][M];
bool cmp(node n1, node n2) {return n1.diff > n2.diff;}
int Solve1()
{
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n / 2; j++)	
			for (int k = 0; k <= n / 2; k++)
			{
				int l = i - j - k;
				if (l > n / 2) continue;
				if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + a[i]);
				if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + b[i]);
				if (l > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + c[i]);
			}
	int ans1 = 0;
	for (int j = 0; j <= n / 2; j++)
		for (int k = 0; k <= n / 2; k++)
			if (n - j - k <= n / 2)
				ans1 = max(ans1, dp[n][j][k]);
	return ans1;
}
int Solve2()
{
	for (int i = 1; i <= n; i++) d[i] = {i, a[i] - b[i]}; 
	sort(d + 1, d + n + 1, cmp);
	int ans2 = 0;
	for (int i = 1; i <= n / 2; i++) ans2 += a[d[i].id];
	for (int i = n / 2 + 1; i <= n; i++) ans2 += b[d[i].id];
	return ans2;
}
int main()
{	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		bool flagB = 1;
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			if (c[i] != 0) flagB = 0;
		}
		if (n <= 200) printf("%d\n", Solve1());
		else if (flagB) printf("%d\n", Solve2());
	}
	return 0;
}
