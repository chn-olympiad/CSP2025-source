#include <bits/stdc++.h>
#define all(x) x.begin (), x.end ()
#define x first
#define y second
using namespace std;
using ll = long long;
using db = double;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;

template <typename T>
void cmax (T &a, const T &b) {if (a < b) a = b;}
template <typename T>
void cmin (T &a, const T &b) {if (a > b) a = b;}

template <typename T>
ostream & operator << (ostream &os, vector <T> &a) {
	for (auto &v : a) os << v << ' ';
	return os;
}

class DSU {
public:
	vector <int> fa, siz;
	DSU (int n) {init (n + 1);}
	void init (int n) {
		fa.resize (n + 1); iota (all(fa), 0);
		siz.resize (n + 1); fill (all(siz), 1);
	}
	
	int find (int x) {
		return fa[x] == x ? x : (fa[x] = find (fa[x]));
	}
	
	bool merge (int v, int u) {
		auto fv = find (v), fu = find (u);
		if (fv == fu) return 0;
		if (siz[fv] > siz[fu]) swap (fv, fu);
		siz[fu] += siz[fv]; fa[fv] = fu;
		return 1;
	}
	
	bool same (int v, int u) {
		auto fv = find (v), fu = find (u);
		return fv == fu;
	}
};

struct Node {
	int v, u; ll w;
	Node () : v (0), u (0), w (0ll) {}
	Node (int _v, int _u, ll _w) : v (_v), u (_u), w (_w) {}
	bool operator < (const Node &rhs) const {
		return w < rhs.w;
	}
};

namespace sub1 {
	int n, m, k;
	vector <Node> e;
	
	void solve () {
		DSU dsu (n);
		
		int cnt = 0;
		ll ans = 0;
		for (auto &x : e) {
			int v = x.v, u = x.u; ll w = x.w;
			if (!dsu.merge (v, u)) continue;
			ans += w;
			cnt++;
			if (cnt == n - 1) break;
		}
		cout << ans << '\n';
	}
}

void init () {
	
}

void solve () {
	int n, m, k; cin >> n >> m >> k;
	vector <Node> e; e.reserve (m);
	for (int i = 1; i <= m; i++) {
		int v, u; ll w; cin >> v >> u >> w;
		e.push_back (Node (v, u, w));
	}
	sort (all(e));
	
//	if (k == 0) {
//		sub1 :: n = n;
//		sub1 :: m = m;
//		sub1 :: k = k;
//		sub1 :: e = move (e);
//		sub1 :: solve ();
//		return ;
//	}
	
	vector <ll> s (k, 0ll);
	vector <vector <Node>> a (k, vector <Node> (0));
	for (int i = 0; i < k; i++) {
		cin >> s[i];
		a[i].reserve (n);
		for (int j = 1; j <= n; j++) {
			ll w; cin >> w;
			a[i].push_back (Node (j, n + i + 1, w));
		}
		sort (all(a[i]));
	}
	
//	for (int i = 0; i < k; i++) {
//		for (auto &x : a[i]) cerr << '(' << x.v << ", " << x.u << ", " << x.w << ')' << ' ';
//		cerr << '\n';
//	}
	
	vector <ll> sum ((1 << k) + 1, 0ll);
	vector <int> siz ((1 << k) + 1, 0);
	for (int msk = 0; msk < (1 << k); msk++) for (int j = 0; j < k; j++) if (msk & (1 << j))
		sum[msk] += s[j], siz[msk]++;

	vector <vector <Node>> e2 ((1 << k) + 1, vector <Node> (0, Node ()));
	DSU dsu (n + k + 1);
	
	vector <ll> dp ((1 << k) + 1, INF); dp[0] = 0;
	int cnt = 0;
	for (auto &x : e) {
		int v = x.v, u = x.u; ll w = x.w;
		if (!dsu.merge (v, u)) continue;
		dp[0] += w;
		e2[0].push_back (x);
		cnt++;
		if (cnt == n - 1) break;
	}
	
	for (int msk = 0; msk < (1 << k); msk++) for (int j = 0; j < k; j++) if (!(msk & (1 << j))) {
		dsu.init (n + k + 1);
		int cnt = n + siz[msk];
		vector <pair <int, ll>> d (k + 1, pair <int, ll> (0, 0ll));
		ll res = dp[msk | (1 << j)]; dp[msk | (1 << j)] = 0;
		for (int p1 = 0, p2 = 0; p1 < e2[msk].size () || p2 < a[j].size ();) {
			int v = 0, u = 0; ll w = 0;
			if (p1 >= e2[msk].size () || a[j][p2].w < e2[msk][p1].w) {
				v = a[j][p2].v;
				u = a[j][p2].u;
				w = a[j][p2].w;
				p2++;
			}
			else if (p2 >= a[j].size () || a[j][p2].w >= e2[msk][p1].w) {
				v = e2[msk][p1].v;
				u = e2[msk][p1].u;
				w = e2[msk][p1].w;
				p1++;
			}
			
			if (!dsu.merge (v, u)) continue;
			dp[msk | (1 << j)] += w;
			e2[msk | (1 << j)].push_back (Node (v, u, w));
			if (v > n) d[v - n].x++, d[v - n].y += w;
			if (u > n) d[u - n].x++, d[u - n].y += w;
			cnt--;
			if (cnt == 0) break;
		}
		
		for (int i = 1; i <= k; i++) if (d[i].x == 1)
			dp[msk | (1 << j)] -= d[i].y;
		dp[msk | (1 << j)] += sum[msk | (1 << j)];
		
		cmin (dp[msk | (1 << j)], res);
	}
	
	ll ans = INF;
	for (int msk = 0; msk < (1 << k); msk++) cmin (ans, dp[msk]);
	cout << ans << '\n';
	
//	for (int msk = 0; msk < (1 << k); msk++) {
//		for (int j = 0; j < k; j++) if (msk & (1 << j)) cerr << j << ' ';
//		cerr << ": ";
//		cerr << dp[msk] << ' ' << siz[msk] << '\n';
//		for (auto &x : e2[msk]) cerr << '(' << x.v << ", " << x.u << ", " << x.w << ')' << ' ';
//		cerr << '\n';
//	}
}

int main () {
#ifndef LOCAL
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
#endif
	ios :: sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	
	init ();
	
	int t = 1;
//	cin >> t;
	while (t--) solve ();
}
