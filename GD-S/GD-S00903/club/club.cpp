#include <bits/stdc++.h>
#define fst first
#define scd second
#define pb emplace_back
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while (c < '0' || c > '9') {
		f |= (c == '-');
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return f ? -x : x;
}

const int maxn = 100100;

ll n, a[maxn][3], b[maxn], f[maxn];

void solve() {
	n = read();
	int c[3] = {};
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		a[i][0] = read();
		a[i][1] = read();
		a[i][2] = read();
		ans += max({a[i][0], a[i][1], a[i][2]});
		b[i] = max_element(a[i], a[i] + 3) - a[i];
		++c[b[i]];
	}
	if (max({c[0], c[1], c[2]}) <= n / 2) {
		printf("%lld\n", ans);
		return;
	}
	int p = max_element(c, c + 3) - c, tot = 0;
	for (int i = 1; i <= n; ++i) {
		if (b[i] == p) {
			ll d[3] = {a[i][0], a[i][1], a[i][2]};
			sort(d, d + 3);
			f[++tot] = d[1] - a[i][p];
		}
	}
	sort(f + 1, f + tot + 1, greater<ll>());
	for (int i = 1; i <= c[p] - n / 2; ++i) {
		ans += f[i];
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = read();
	while (T--) {
		solve();
	}
	return 0;
}
