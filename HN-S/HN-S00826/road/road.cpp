#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 1e4 + 105, kMaxM = 1e6 + 5;

int n, m, k, cnt, ct[kMaxN], a[15][kMaxN];

int fa[kMaxN], sz[kMaxN];
struct Node {
	int x, y, w;
	bool operator<(const Node &_) const {
		return w < _.w;
	}
} e[kMaxM], e_[kMaxM];

int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
int Merge(int x, int y) {
	x = Find(x), y = Find(y);
	if (x != y) {
		if (sz[x] > sz[y]) swap(x, y);
		fa[x] = y, sz[y] += sz[x];
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].x >> e[i].y >> e[i].w;
	}	
	for (int i = 0; i < k; i++) {
		cin >> ct[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	sort(e + 1, e + m + 1);
	iota(fa + 1, fa + n + 1, 1);
	fill(sz + 1, sz + n + 1, 1);
	for (int i = 1; i <= m; i++) {
		int fx = Find(e[i].x), fy = Find(e[i].y);
		if (fx != fy) {
			fa[fx] = fy;
			e_[++cnt] = e[i];
			if (cnt == n - 1) break;
		}
	}
	int ans = 1e9;
	for (int S = 0; S < (1 << k); S++) {
		int t = n, idx = 0;
		for (int i = 1; i <= cnt; i++) {
			e[++idx] = e_[i];
		}
		int s = 0, c = 0;
		for (int i = 0; i < k; i++) {
			if (S >> i & 1) {
				s += ct[i];
				t++;
				for (int j = 1; j <= n; j++) {
					e[++idx] = {t, j, a[i][j]};
				}
			}
		}
		iota(fa + 1, fa + t + 1, 1);
		fill(sz + 1, sz + t + 1, 1);
		sort(e + 1, e + idx + 1);
		for (int i = 1; i <= idx; i++) {
			int fx = Find(e[i].x), fy = Find(e[i].y);
			if (fx != fy) {
				fa[fx] = fy;
				s += e[i].w, c++;
				if (c == t - 1) break;
			}
		}
//		cout << S << ' ' << s << '\n';
		ans = min(ans, s);
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
