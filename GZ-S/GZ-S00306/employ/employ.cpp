//GZ-S00306 贵阳市云城中学 王乾隆
#include <bits/stdc++.h>
#define X first
#define Y second
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld = double;
using pii = pair<int, int>;
constexpr int maxn = 2e5 + 10, mod = 998244353;
char a[505]; int c[505], p[505], n, m, f[2][19][1 << 19]; // f[i][j][S] 前 i 个人录用了 j 个，已选人集合为 S 的方案数 
void add(int& x, int y) { x += y; if (x >= mod) x -= mod; } 
int main() {
 	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, a + 1);
	rep(i, 1, n) scanf("%d", &c[i]);
	if (n <= 1) {
		int ans = 0;
		rep(i, 1, n) p[i] = i;
		do {
			int w = 0, s = 0;
			rep(i, 1, n) if (a[i] == '0' || s >= c[p[i]]) ++s;
			if (n - s >= m) ++ans;
		} while (next_permutation(p + 1, p + n + 1));
		printf("%d\n", ans);
	}
	else if (n <= 18) {
		f[0][0][0] = 1;
		rep(i, 1, n) {
			memset(f[i & 1], 0, sizeof(f[i & 1]));
			rep(j, 0, i) {
				rep(s, 0, (1 << n) - 1) {
					if (__builtin_popcount(s) != i) continue;
					rep(k, 1, n) if (s >> k - 1 & 1) {
						// i 录用了 j 个人, i - 1 录用了 j - 1 个人 
						if (j && c[k] > (i - 1) - (j - 1) && a[i] == '1') add(f[i & 1][j][s], f[i & 1 ^ 1][j - 1][s ^ (1 << k - 1)]);
						else add(f[i & 1][j][s], f[i & 1 ^ 1][j][s ^ (1 << k - 1)]);
					}
				}
			}
		} 
		int ans = 0;
		rep(i, m, n) add(ans, f[n & 1][i][(1 << n) - 1]);
		printf("%d\n", ans);
	}
	else puts("0"); 
	return 0;
}
/*
将 c 排序 

考虑按 c[i] 排序连续段 dp
3 2
101
1 1 2
*/ 
