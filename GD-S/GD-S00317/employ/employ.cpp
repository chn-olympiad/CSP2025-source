#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int mod = 998244353;

int n, m;
int f[1 << N - 2][N], c[N], popcnt[1 << N - 2];
char s[N];

void add(int &u, int v) { u = u + v >= mod ? u + v - mod : u + v; }

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < (1 << n); i++) popcnt[i] = popcnt[i >> 1] + (i & 1);
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j <= popcnt[i]; j++)
			for (int k = 1; k <= n; k++)
				if (~i & (1 << k - 1))
				{
					if (s[popcnt[i] + 1] == '1' && popcnt[i] - j < c[k]) add(f[i | (1 << k - 1)][j + 1], f[i][j]);
					else add(f[i | (1 << k - 1)][j], f[i][j]);
				}
	int ans = 0;
	for (int i = m; i <= n; i++) add(ans, f[(1 << n) - 1][i]);
	printf("%d", ans);
	return 0;
}
