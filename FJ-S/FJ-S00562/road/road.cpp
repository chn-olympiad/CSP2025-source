#include <bits/stdc++.h>
#define ri register int

using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0; bool f = 1;
	char ch = getchar();
	while(ch < 48 || ch > 57) {
		if(ch == 45) f = 0;
		ch = getchar();
	}
	while(ch >= 48 && ch <= 57) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return f ? x : -x;
}

constexpr int N = 1e4 + 20, M = 1.1e6 + 10;

int n, m, k;

struct Edge {
	int x, y, w;
}e[M];
int c[13];
int a[13][N];

int fa[N];
inline int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void slv1() {
	sort(e + 1, e + 1 + m, [&](Edge A, Edge B) {
		return A.w < B.w;
	});
	for(ri i = 1; i <= n; ++i) fa[i] = i;
	ll ans = 0;
	for(ri i = 1; i <= m; ++i) {
		int fx = find(e[i].x), fy = find(e[i].y);
		if(fx == fy) continue;
		ans += e[i].w;
		fa[fy] = fx;
	}
	cout << ans << "\n";
}

inline bool checkA() {
	for(ri i = 1; i <= k; ++i) {
		if(c[i]) return 0;
		for(ri j = 1; j <= n; ++j) {
			if(a[i][j]) return 0;
		}
	}
	return 1;
}

inline void Solve() {
	n = rd(), m = rd(), k = rd();
	for(ri i = 1; i <= m; ++i) {
		e[i].x = rd(), e[i].y = rd(), e[i].w = rd();
	}
	
	for(ri i = 1; i <= k; ++i) {
		c[i] = rd();
		for(ri j = 1; j <= n; ++j) a[i][j] = rd();
	}
	
	if(checkA()) return cout << 0 << "\n", void();
	slv1();
	
	
	
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);


	Solve();
	return 0;
}

