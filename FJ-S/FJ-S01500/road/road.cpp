#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
constexpr int N = 1e4 + 5, M = 1e6 + 5; 
struct Edge {
	int u, v, w;
}e[M];

bool cmp (Edge a, Edge b) {
	return a.w < b.w;
}

int n, m, f[N], tot, k, ci[15], c[15][N], u, v, w, ans = 1e18;
vector <int> use;

bool flag = false;

int find (int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void merge (int x, int y) {
	int rt = find (x), rt1 = find (y);
	f[rt] = f[rt1];
}

void solve () {
//	cout  << 1;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
	int yuann = n;
//	cout << n;
	for (int i = 1; i <= k; i ++) {
		cin >> ci[i];
		for (int j = 1; j <= yuann; j ++) cin >> c[i][j];
		if (!ci[i]) {
			++ n;
			for (int j = 1; j <= yuann; j ++) {
				e[++ m] = {j, n, c[i][j]}; 
			} 
		} else use.push_back (i);
	}
//	cout << n;
	
	k = use.size ();
	for (int bin = 0; bin < (1 << k); bin ++) {
		int res = 0;
		int cnt = m, cntn = n, ttt = 0;
		for (int rrr = 0; rrr < k; rrr ++) {
			if ((bin >> rrr) & 1) {
				++ cntn;
				ttt += ci[use[rrr]];
//				cout << n;
//				cout << n << ' ' << yuann << endl;
				for (int i = 1; i <= n; i ++) e[++ cnt] = {i, cntn, c[use[rrr]][i]};
			}
		}
		for (int i = 1; i <= cntn; i ++) f[i] = i;
		sort(e + 1, e + 1 + cnt, cmp);
		tot = 0;
		for (int i = 1; i <= cnt; i ++) {
			if (tot == cntn - 1) break;
			u = e[i].u, v = e[i].v, w = e[i].w;
//			cout << 'o';
			if (find (u) == find (v)) {
				continue;
			}
//			cout << bin << ' ' << res << ' ' << u << ' ' << v << endl;
			merge (u, v); res += w, tot ++;
		}
		ans = min (ans, res + ttt);
	}
	cout << ans;
}

signed main () {  // byd t1 没打出来 t2也只会暴力 原地退役。。。 
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
//	freopen ("road2.in", "r", stdin);
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	solve ();

	return 0;
}

