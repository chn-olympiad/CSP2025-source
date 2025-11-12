#include <bits/stdc++.h>

using namespace std;

const int N = 37;

int t, n, a[N][3], g[3], f[N][N][N][N], ans;

void dfs(int k, int st, int cur)
{
	if (f[k][g[0]][g[1]][g[2]] >= cur) return;
	f[k][g[0]][g[1]][g[2]] = cur;
	if (k >= n)
	{
		ans = max(ans, cur);
		return;
	}
	
	for (int i = 0; i < 3; ++i)
		if (g[i] < n / 2)
		{
			g[i]++;
			dfs(k + 1, i, cur + a[k + 1][i]);
			g[i]--;
		}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j < 3; ++j)
				cin >> a[i][j];
		
		ans = 0;
		memset(f, 0x8f, sizeof(f));
		memset(g, 0, sizeof(g));
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	
	return 0;
}
