#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N = 505;
string s;
int c[N];
int p[N];
const int mod = 998244353;

void solve() {
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) p[i] = i;
	int ans = 0;
	do {
		int qt = 0, suc = 0;
		for (int i = 1; i <= n; i++) {
			if (qt >= c[p[i]]) {
				qt++;
				continue;
			}
			if (s[i - 1] == '0') qt++;
			else suc++;
		}
		if (suc >= m) ans++;
		if (ans >= mod) ans -= mod;
	} while (next_permutation(p + 1, p + n + 1));
	printf("%lld\n", ans);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	solve();
	return 0;
}
