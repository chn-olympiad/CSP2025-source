#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
struct Edge {
	int u, v;
	long long w;
	bool operator < (const Edge &b) const {
		return w < b.w;
	}
};

struct DSU {
	int n;
	vector<int> f;
	DSU(int n) : n(n), f(n + 1) {
		for (int i = 1; i <= n; ++i) f[i] = i;
	}
	int find(int x) {
		if (f[x] == x) return x;
//		cout << x << "\n";
		return f[x] = find(f[x]);
	}
};

int lowbit(int x) {
	return x & -x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<Edge> e0(m + 1), e1;
	e1.push_back({0, 0, 0});
	for (int i = 1; i <= m; ++i) {
		cin >> e0[i].u >> e0[i].v >> e0[i].w;
	}
	sort(e0.begin() + 1, e0.end());
	long long ans = 0;
	vector<vector<PII>> e(n + 1);
	DSU ds0(n);
	for (int i = 1; i <= m; ++i) {
		int fu = ds0.find(e0[i].u), fv = ds0.find(e0[i].v);
		if (fu == fv) {
//			if (e0[i].w == e0[i - 1].w) {
//				e1.push_back({e0[i].u, e0[i].v, e0[i].w});
//			}
			continue;
		}
		ds0.f[fu] = fv;
		e1.push_back({e0[i].u, e0[i].v, e0[i].w});
		ans += e0[i].w;
	}
//	cerr << ans << endl;
	vector<int> c(k + 1);
	vector<vector<int>> a(k + 1, vector<int> (n + 1));
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int bin = 1; bin <= (1 << k) - 1; ++bin) {
		long long cnt = 0;
		int nd = n, md = e1.size() - 1;
		vector<Edge> e(e1);
		for (int j = 1; j <= k; ++j) {
			if (bin >> (j - 1) & 1) {
//				cerr << j << " " << bin << endl;
				nd++;
				cnt += c[j];
				for (int i = 1; i <= n; ++i) {
					e.push_back({nd, i, a[j][i]});
				}
				md += n;
			}
		}
//		cerr << e.size() << " " << md << endl;
		sort(e.begin() + 1, e.end());
		DSU ds(nd);
		for (int i = 1; i <= md; ++i) {
//			cerr << e[i].u << " " << e[i].v << " " << md << " " << e.size() << "\n";
			int fu = ds.find(e[i].u), fv = ds.find(e[i].v);
//			cerr << fu << " " << fv << " " << i << endl;
			if (fu == fv) continue;
//			if (fu > fv) swap(fu, fv);
			ds.f[fu] = fv;
			cnt += e[i].w;
//			cerr << e[i].u << endl;
		}
//		cerr << cnt << endl;
		ans = min(ans, cnt);
//		if (cnt > ans) {
////			bin += lowbit(bin);
//		} else {
//			ans = cnt;
//		}
	}
	cout << ans << "\n";
	return 0;
}

