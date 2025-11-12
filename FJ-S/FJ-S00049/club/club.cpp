#include <bits/stdc++.h>
using namespace std;
#define IC isdigit(c)
#define GC c=getchar()
#define il inline
il void rd(auto &x) { char GC; x = 0; bool f = 0;
	for (; !IC; GC) f |= x == '-';
	for (; IC; GC) x = x * 10 + (c - 48);
	f && (x = -x);
}
il void rd(auto &x, auto &...y) { rd(x); rd(y...);
}
#define U(i,l,r) for (int i(l),END##i(r); i<=END##i; ++i)
#define D(i,l,r) for (int i(l),END##i(r); i>=END##i; --i)
#define ms(x, v) memset(x, v, sizeof(x))
#define vc vector
#define pb push_back
#define eb emplace_back
using ll = long long;

const int N = 100005;
int n; ll a[N][3];

ll solve() {
	rd(n);
	int b[N] {};
	U (i, 1, n) {
		U (j, 0, 2) rd(a[i][j]);
		b[i] = max_element(a[i], a[i] + 3) - a[i];
	}
	int cnt[3] {}; ll tot = 0;
	U (i, 1, n) {
		++cnt[b[i]];
		tot += a[i][b[i]];
	}
	if (*max_element(cnt, cnt + 3) <= n / 2)
		return tot;
	
	int k = max_element(cnt, cnt + 3) - cnt;
	vc<tuple<ll, int, int>> dec;
	
	bool vis[N] {};
	U (i, 1, n) if (b[i] == k) U (j, 0, 2) if (j != k) {
		dec.eb(-a[i][k] + a[i][j], i, j);
	}
	sort(dec.begin(), dec.end(), greater<tuple<int, int, int>>());
	
	int p = cnt[k] - (n / 2);
	for (auto [v, i, j] : dec) {
		if (vis[i]) continue;
		if (!p) break;
		--p;
		vis[i] = 1;
		tot += v; ++cnt[j]; --cnt[k];
		assert(cnt[j] <= n / 2);
	}
	return tot;
}

void clear() {
	n = 0; ms(a, 0);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; rd(t);
	while (t--) {
		ll ans = solve();
		printf("%lld\n", ans);
		clear();
	}
}
