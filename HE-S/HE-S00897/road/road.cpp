#include <bits/stdc++.h>

#define ll long long

const ll N = 1e4 + 5, M = 2e6 + 5, K = 15;

ll n, m, k;
struct edge {
	ll u, v, w;
	
	bool operator < (const edge& other) const {
		return w < other.w;
	}
} e[M];
ll c[K], a[K][N];
ll ans;

ll read() {
	ll res = 0, i = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') i = -i;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * i;
}

void write(ll x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

struct DSU {
	ll fa[N];
	
	inline void init() {
		std::iota(fa + 1, fa + n + 1, 1);
	}
	
	inline ll find(ll x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
} dsu;

void addedge() {
	for (ll i = 1, p; i <= k; ++i) {
		p = 0;
		for (ll j = 1; j <= n; ++j)
			if (!a[i][j]) {
				p = j;
				break;
			}
		for (ll j = 1; j <= n; ++j)
			if (j != p)
				e[++m] = {p, j, a[i][j]};
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	dsu.init();
	for (ll i = 1; i <= m; ++i)
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	bool keyA = true;
	bool tk;
	for (ll i = 1; i <= k; ++i) {
		c[i] = read();
		if (c[i]) keyA = false;
		tk = false;
		for (ll j = 1; j <= n; ++j) {
			a[i][j] = read();
			if (!a[i][j]) tk = true;
		}
		if (!tk) keyA = false;
	}
	if (keyA) addedge();
	std::sort(e + 1, e + m + 1);
	for (ll i = 1, u, v, w; i <= m; ++i) {
		u = e[i].u, v = e[i].v, w = e[i].w;
		u = dsu.find(u), v = dsu.find(v);
		if (u == v) continue;
		dsu.fa[u] = v;
		ans += w;
	}
	write(ans), puts("");
	return 0;
}

/*
16:36
86min
48pts
tiaole.
*/
