#include <bits/stdc++.h>
namespace GDS03068 {
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
typedef pair<ll, pair<int, int>> pip;
#define fi first
#define se second
const int maxn = 1e4 + 40, maxm = 1e6 + 60, maxk = 12;
int n, m, k;
int fa[maxn];
int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
vector<pip> E, e1;
vector<pii> e2[maxk];
ll c[maxk], a[maxk][maxn];
ll ans, ANS;
int he2[maxk];
vector<int> ch;
ll calc(int S) {
	ch.clear();
	ll an = 0;
	int n1 = n;
	for (int i = 1; i <= k; ++i)
		if (S >> (i - 1) & 1) {
			an += c[i];
			ch.emplace_back(i);
			++n1;
			he2[i] = 0;
		}
	if (an >= ANS) return an;
	iota(fa + 1, fa + 1 + n + k, 1);
	pip use;
	for (int i = 1, hee = 0, sel; i < n1; ++i) {
		while (hee < n - 1 && find(e1[hee].se.fi) == find(e1[hee].se.se)) ++hee;
		if (hee < n - 1) use = e1[hee];
		else use = {int(2e9), {1, 1}};
		for (int j : ch) {
			sel = find(n + j);
			while (he2[j] < n && find(e2[j][he2[j]].se) == sel) ++he2[j];
			if (he2[j] < n && e2[j][he2[j]].fi < use.fi)
				use = {e2[j][he2[j]].fi, {j + n, e2[j][he2[j]].se}};
		}
		an += use.fi;
		fa[find(use.se.fi)] = find(use.se.se);
		if (an >= ANS) return an;
	}
	return an;
}
void init() {
}
void Mian() {
	init();
	cin >> n >> m >> k;
	if (n == 1) {
		cout << "0\n";
		return;
	}
	E.reserve(m);
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		E.push_back({w, {u, v}});
	}
	sort(E.begin(), E.end());
	iota(fa + 1, fa + 1 + n, 1);
	int cnt = 1;
	e1.reserve(n);
	for (pip i : E) {
		int u = find(i.se.fi), v = find(i.se.se);
		if (u == v) continue;
		fa[u] = v;
		ans += i.fi;
		++cnt;
		e1.emplace_back(i);
		if (cnt >= n)
			break;
	}
	ANS = ans;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		e2[i].reserve(n);
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			e2[i].emplace_back(a[i][j], j);
		}
		sort(e2[i].begin(), e2[i].end());
	}
	ch.reserve(k);
	for (int S = 1, ms = (1 << k) - 1; S <= ms; ++S)
		ANS = min(ANS, calc(S));
	cout << ANS << '\n';
}
}
int main() {
#ifndef LOCALruanhuaxuan
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T = 1;
//	std::cin >> T;
	while (T--) GDS03068::Mian();
	return 0;
}

