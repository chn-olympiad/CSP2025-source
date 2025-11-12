#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back

const int N = 507, Mod = 998244353;
int n, m, c[N], fl; string s;
int p[N], ans;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) fl += (s[i] ^ 48);
	if (fl < m) return putchar(48), 0;
	if (n <= 10) {
		for (int i = 1; i <= n; i++) p[i] = i;
		do {
			int cnt = 0, cnt2 = 0;
			for (int i = 1; i <= n; i++)
				if (c[p[i]] > cnt2 && s[i - 1] ^ 48) cnt++;
				else cnt2++;
			(ans += (cnt >= m)) %= Mod;
		} while (next_permutation(p + 1, p + 1 + n));
		printf("%d\n", ans);
	}
}
