#include <bits/stdc++.h>
using namespace std;
int n, m, k, fa[10209];
long long c[12];
pair<long long, int> a[12][10108];

inline int get_fa(int i) {
	if (i == fa[i]) return i;
	return fa[i] = get_fa(fa[i]);
}

struct Edge {
	int u, v;
	long long w;
	inline bool operator < (const Edge &e) const {
		return w < e.w;
	}
} e1[1000006], e2[101006], tmp[101006];
int e2t;

inline void merges(int i, int nt) {
	int it1 = 1, it2 = 1, nowt = 0;
	while (it1 <= n && it2 <= e2t) {
		if (a[i][it1].first < e2[it2].w) {
			tmp[++nowt] = {nt, a[i][it1].second, a[i][it1].first};
			++it1;
		} else {
			tmp[++nowt] = e2[it2++];
		}
	}
	while (it1 <= n) {
		tmp[++nowt] = {nt, a[i][it1].second, a[i][it1].first};
		++it1;
	}
	while (it2 <= e2t) {
		tmp[++nowt] = e2[it2++];
	}
	e2t = nowt;
	for (int i = 1; i <= nowt; ++i) e2[i] = tmp[i];
}

signed main() {
	freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e1[i].u >> e1[i].v >> e1[i].w;
	}
	sort(e1 + 1, e1 + m + 1);
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j].first;
			a[i][j].second = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	long long ans = 1ll << 60;
	for (int f = 0; f < (1 << k); ++f) {
		long long nowans = 0;
		for (int i = 1; i <= n + k; ++i) fa[i] = i;
		e2t = 0;
		int nt = n;
		for (int i = 1; i <= k; ++i) {
			if (f & (1 << (i - 1))) {
				++nt;
				merges(i, nt);
				nowans += c[i];
			}
		}
		int it1 = 1, it2 = 1, ltk = nt;
		while (1) {
			Edge now = {0, 0, 1ll << 60}, yns;
			if (it1 <= m && (it2 > e2t || e1[it1] < e2[it2])) now = e1[it1++];
			else now = e2[it2++];
			yns = now;
			now.u = get_fa(now.u);
			now.v = get_fa(now.v);
			if (now.u != now.v) {
				fa[now.u] = now.v;
				nowans += now.w;
				if (nowans > ans || --ltk == 1) break;
			}
		}
		ans = min(ans, nowans);
	}
	cout << ans << "\n";
	return 0;
}
