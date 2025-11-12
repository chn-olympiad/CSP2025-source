#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n, a[N], c[N][N];
void init()
{
	c[1][1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (j == 1 || j == i)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	init();
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n <= 3)
	{
		int ans = 0;
		if (max({a[1], a[2], a[3]}) * 2 > a[1] + a[2] + a[3]) ans++;
		printf("%d", ans);
		return 0;
	}
	int ans = 0;
//	for (int i = 3; i <= n; i++)
//		ans = (ans + c[n][i]) % mod;
	printf("%d", ans);
	return 0;
}
