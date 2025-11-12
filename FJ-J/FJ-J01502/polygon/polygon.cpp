#include <bits/stdc++.h>
using namespace std;

const int N = 5010, M = 1e4 + 10, mod = 998244353;

int a[N];
int f[2][M];

void solve()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int m = a[n] * 2 + 1, res = 0; f[0][0] = 1;
	for (int i = 0; i < n; i ++ )
	{
		if (i + 1 >= 3)
		{
			for (int j = a[i + 1] + 1; j <= m; j ++ ) res = (res + f[i & 1][j]) % mod;
		}
		for (int j = 0; j <= m; j ++ ) f[(i + 1) & 1][j] = 0;
		for (int j = 0; j <= m; j ++ )
		{
			if (!f[i & 1][j]) continue;
			f[(i + 1) & 1][j] = (f[(i + 1) & 1][j] + f[i & 1][j]) % mod;
			int k = min(j + a[i + 1], m);
			f[(i + 1) & 1][k] = (f[(i + 1) & 1][k] + f[i & 1][j]) % mod;
		}
	}
	printf("%d\n", res);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
