#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 505;
int f[1000000][20];
int c[N], ct[N];
char s[N];
void add(int &x, int y) {if ((x += y) >= mod) x -= mod;}
int ppcnt(int x, int res = 0) {
	while (x) res += x & 1, x >>= 1;
	return res;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++)
		ct[i] = ct[i - 1] + (s[i] == '0');
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	if (m > n - ct[n]) return puts("0"), 0;
	if (n <= 18) {
		f[0][0] = 1;
		for (int i = 1; i < 1 << n; i++)
			for (int j = 0; j <= n; j++) {
				int cnt = ppcnt(i);
				if (j > cnt) continue;
				for (int k = 1; k <= n; k++)
					if (i & (1 << k - 1)) {
						if (s[cnt] == '1' && j && cnt - j < c[k])
							add(f[i][j], f[i ^ (1 << k - 1)][j - 1]);
						if (s[cnt] == '0' || cnt - j - 1 >= c[k])
							add(f[i][j], f[i ^ (1 << k - 1)][j]);
					}
			}
		int res = 0;
		for (int i = m; i <= n; i++)
			add(res, f[(1 << n) - 1][i]);
		return printf("%d", res), 0;
	}
	if (m == n) {
		int ans = 1;
		for (int i = 2; i <= n; i++)
			ans = 1ll * ans * i % mod;
		for (int i = 1; i <= n; i++)
			if (!c[i]) return puts("0"), 0;
		return printf("%d", ans), 0;
	}
	return 0;
}
