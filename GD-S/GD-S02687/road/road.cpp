#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr const int N = 1e4 + 13;
vector<tuple<int, int, int>> E;
int c[13], fa[N];

int fnd(int x)
{ return fa[x] == x? x: fa[x] = fnd(fa[x]); }

LL Kruskal() {
	sort(begin(E), end(E));
	LL res = 0;
	for(const auto& p: E) {
		int w = get<0>(p), u = get<1>(p), v = get<2>(p),
			fu = fnd(u), fv = fnd(v);
		if(fu == fv)
			continue;
		fa[fu] = fv;
		res += w;
	}
	return res;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	iota(fa+1, fa+n+k+1, 1);
	for(int u, v, w; m--; ) {
		cin >> u >> v >> w;
		E.emplace_back(w, u, v);
	}
	for(int i = 1, w; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++j) {
			cin >> w;
			E.emplace_back(w, n+i, j);
		}
	}
	cout << Kruskal() << endl;
	return 0;
}
