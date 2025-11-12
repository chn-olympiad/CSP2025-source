#include <bits/stdc++.h>
#define ll long long
#define int long long
#define endl '\n'
#define pii pair<int, int>
using namespace std;
const int maxn = 1e4 + 5; // O(n^2)???
struct edge {
	int to, val;
};
struct node1 {
	int val, u, v;
	bool operator <(node1 x) {
		return val < x.val; 
	}
};
int n, m, k;
vector<edge> e[maxn];
vector<int> c;
vector<edge> g[15];
// 并查集？
// 看着像 
// 最小生成树 
int fa[maxn], cnt[maxn];
int _find(int x) {
	return (fa[x] == x ? x : fa[x] = _find(fa[x]));
}
void _union(int x, int y) {
	x = _find(x), y = _find(y);
	if (x == y) return ;
	if (cnt[x] > cnt[y]) swap(x, y); // cnt_x < cnt_y
	fa[x] = y;
	cnt[y] += cnt[x];
}
vector<node1> h;
void solve1() {
	// init
	for (int i = 1; i <= n; i++) fa[i] = i, cnt[i] = 1;
	//---
	for (int i = 1; i <= m; i++) {
		int u, v, val;
		scanf("%lld%lld%lld", &u, &v, &val);
		h.push_back({val, u, v});
	}
	sort(h.begin(), h.end());
	int ans = 0;
	for (auto ns: h) {
		int u = ns.u, v = ns.v, val = ns.val;	
		if (_find(u) == _find(v)) continue;
//		cout << "lian:" << u << ' ' << v << "\ncost:" << val << endl;
		_union(u, v);
		ans += val;
	}
	cout << ans << endl;
}
void solve2() {
	for (int i = 1; i <= n; i++) fa[i] = i, cnt[i] = 1;
	for (int i = 1; i <= k; i++) {
		for (auto now: g[i]) {
			h.push_back({now.val + c[k - 1], now.to, i});
		}
	}
	sort(h.begin(), h.end());
	int ans = 0;
	for (auto x: h) {
		int val = x.val, u = x.u, v = x.v;
		if (_find(u) == _find(v)) continue;
		_union(u, v);
		ans += val;
	}
	cout << ans << endl;
}
void solve() {
	
	// init
	for (int i = 1; i <= n; i++) fa[i] = i, cnt[i] = 1;
	//---
	for (int i = 1; i <= m; i++) {
		int u, v, val;
		scanf("%lld%lld%lld", &u, &v, &val);
		h.push_back({val, u, v});
	}
	sort(h.begin(), h.end());
	int ans = 0;
	for (auto ns: h) {
		int u = ns.u, v = ns.v, val = ns.val;	
		if (_find(u) == _find(v)) continue;
//		cout << "lian:" << u << ' ' << v << "\ncost:" << val << endl;
		_union(u, v);
		ans += val;
	}
	cout << ans << endl;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0) {
		solve1();
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, val;
		scanf("%lld%lld%lld", &u, &v, &val);
		e[u].push_back({v, val});
		e[v].push_back({u, val}); 
		h.push_back({val, u, v});
	}
	bool f = 0;
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		c.push_back(x);
		if (x != 0) f = 1;
		for (int j = 1; j <= n; j++) {
			int val;
			scanf("%lld", &val);
			g[i].push_back({j, val});
//			if (j == 1) cout << "wheres my a?\n";
		}
	}
	if (!f) {
		solve2(); // A
		return 0;
	}
	solve();
}
