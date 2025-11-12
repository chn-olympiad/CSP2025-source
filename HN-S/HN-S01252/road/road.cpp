#include <bits/stdc++.h>
//#define int long long
using namespace std;

template <typename T> void _p (T x) { cout << x << ", "; }
template <typename T, typename ...R> void _p (T x, R ...r) { _p (x); _p (r...); }
template <typename ...R> void _d (const char *s, R ...r) {
	cout << s << ": "; _p (r...); cout << endl;
}
template <typename T> void _r (const char *s, T x, int n) {
	cout << s << ": {";
	for (int i = 1 ; i < n ; i ++) _p (x [i]);
	cout << x [n] << "}\n";
}
#define debug(...) _d (#__VA_ARGS__, __VA_ARGS__)
#define debua(a,n) _r (#a, a, n);

const int N = 3e4, M = 2e6, K = 20;
int n, m, k, c [K + 5], d [K + 5] [N + 5], fa [N + 5], tag [K + 5], tot, cnt;

int find (int x) {
	return x == fa [x] ? x : (fa [x] = find (fa [x]));
}

void merge (int x, int y) {
	int fx = find (x), fy = find (y);
	if (fx == fy) return ;
	cnt --;
	fa [fx] = find (fy);
}

struct Edge {
	int u, v, w;
	bool operator < (Edge b) const {
		return w > b. w;
	}
} e [3 * M + 5], fe [M + 5], se [M + 5];

void Turn () {
	srand (time (0));
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i ++) {
		int x, y, z; cin >> x >> y >> z;
		fe [i] = {x, y, z};
	} sort (fe + 1, fe + m + 1); long long ans = 0;
	for (int i = 1 ; i <= n ; i ++) fa [i] = i; 
	for (int i = m ; i >= 1 ; i --) {
		int u = fe [i]. u, v = fe [i]. v;
		if (find (u) == find (v)) continue;
		merge (u, v);
		se [++ tot] = fe [i];
		ans += fe [i]. w;
	}
	
	for (int i = 1 ; i <= k ; i ++) {
		cin >> c [i];
		for (int j = 1 ; j <= n ; j ++) {
			cin >> d [i] [j];
		}
	} 
	for (int S = 0 ; S < (1 << k) ; S ++) {
		for (int i = 1 ; i <= n + k ; i ++) fa [i] = i;
		tot = n - 1;
		for (int i = 1 ; i < m ; i ++) e [i] = se [i];
		long long sum = 0;
		cnt = n;
		for (int i = 1 ; i <= k ; i ++) {
			if (S & (1 << (i - 1))) {
				cnt ++;
				sum += c [i];
				for (int j = 1 ; j <= n ; j ++) {
					e [++ tot] = {n + i, j, d [i] [j]};
				}
			}
		} sort (e + 1, e + tot + 1);
		for (int i = tot ; i >= 1 ; i --) {
			int u = e [i]. u, v = e [i]. v, w = e [i]. w;
			if (find (u) == find (v)) continue;
			merge (u, v); sum += w;
			if (cnt == 1) break;
			if (sum >= ans) break;
		}
		
		ans = min (ans, sum);
	}
	
	cout << ans << endl;
}

int _; void Init () {
	ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
	_ = 1;
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
//	cin >> _;
}

	signed main () { Init ();
	while (_ --> 0) 
	Turn (); return 0; }

// 我也太菜了，切掉之后只剩40min了，打T3 T4暴力去了 
