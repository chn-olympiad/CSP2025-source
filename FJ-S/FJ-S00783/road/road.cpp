#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4, M = 1e6, K = 10;
const int INF = 1e18;
int n, m, k, gcnt, ans = INF;
int c[K+5], a[K+5][N+5];
int fa[N*2+5], freecnt;
bool fre[K+5], pur[K+5];
struct Node {
	int u, v, w;
} g[M*3+5], g2[M*3+5];
bool cmp(Node x, Node y) {
	return x.w < y.w;
}
int fd(int x) {
	if (x == fa[x]) return x;
	return fa[x] = fd(fa[x]);
}
int solve () {
	int res = 0, purcnt = 0;
	for (int i = 1; i <= m; i ++) {
		g2[i] = g[i];
	}
	for (int i = 1; i <= k; i ++) {
		if (!pur[i]) continue;
		purcnt ++;
		for (int j = 1; j <= n; j ++) {
			gcnt ++;
			g2[gcnt].u = i + n;
			g2[gcnt].v = j;
			g2[gcnt].w = a[i][j];
		}
	}
	for (int i = 1; i <= n+purcnt; i ++) {
		fa[i] = i;
	}
	sort(g2+1, g2+1+gcnt, cmp);
//	cout << gcnt << "\n";
	int cnt = 0;
	for (int i = 1; i <= gcnt; i ++) {
		int u = g2[i].u, v = g2[i].v;
		int fu = fd(fa[u]), fv = fd(fa[v]);
		if (fu == fv) continue;
		fa[fu] = fv;
		res += g2[i].w;
		cnt ++;
//		cout << cnt << ' ' << n+purcnt-1 << ' ' << u << ' ' << v << ' ' << g[i].w << "\n";
		if (cnt == n+purcnt-1) break;
	}
	return res;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("raod.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		gcnt ++;
		cin >> g[gcnt].u >> g[gcnt].v >> g[gcnt].w;
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		if(!c[i]) {
			fre[i] = true;
			freecnt ++;
		}
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
			gcnt ++;
		}
	}
	for (int i = 0; i < (1 << (k - freecnt)); i ++) {
		int cnt = 0, sum = 0;
		for (int j = 1; j <= k; j ++) {
			if (!fre[j]) cnt ++;
			if (fre[j] || ((i >> (cnt-1)) & 1)){
//				cout << "1 ";
				pur[j] = true;
				sum += c[j];
			}
			else {
//				cout << "0 ";
				pur[j] = false;
			}
		}
//		cout <<"\n";
		gcnt = m;
		ans = min(ans, solve() + sum);
//		cout << "\n";
	}
	cout << ans;
	return 0;
}

//#include <bits/stdc++.h>
//#define int long long
//using namespace std;
//const int N = 1e4, M = 1e6, K = 10;
//int n, m, k, gcnt, ans;
//int c[K+5], a[K+5][N+5];
//int fa[N+5], freecnt;
//bool fre[K+5], pur[K+5];
//struct Node {
//	int u, v, w;
//} g[M*3+5];
//bool cmp(Node x, Node y) {
//	return x.w < y.w;
//}
//int fd(int x) {
//	if (x == fa[x]) return x;
//	return fa[x] = fd(fa[x]);
//}
//int solve () {
//	int res = 0;
//	for (int i = 1; i <= n; i ++) {
//		fa[i] = i;
//	}
//	sort(g+1, g+1+gcnt, cmp);
//	int cnt = 0;
//	for (int i = 1; i <= gcnt; i ++) {
//		int u = g[i].u, v = g[i].v;
//		int fu = fd(fa[u]), fv = fd(fa[v]);
//		if (fu == fv) continue;
//		fa[fu] = fv;
//		res += g[i].w;
//		cnt ++;
////		cout << u << ' ' << v << "\n";
//		if (cnt == n-1) break;
//	}
//	return res;
//}
//signed main () {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("road.in", "r", stdin);
//	freopen("raod.out", "w", stdout);
//	cin >> n >> m >> k;
//	for (int i = 1; i <= m; i ++) {
//		gcnt ++;
//		cin >> g[gcnt].u >> g[gcnt].v >> g[gcnt].w;
//	}
//	for (int i = 1; i <= k; i ++) {
//		cin >> c[i];
//		if(!c[i]) {
//			fre[i] = true;
//			freecnt ++;
//		}
//		for (int j = 1; j <= n; j ++) {
//			cin >> a[i][j];
//			gcnt ++;
//		}
//	}
//	ans = solve();
////	for (int i = 0; i < (1 << (k - freecnt)); i ++) {
////		int cnt = 0;
////		for (int j = 1; j <= k; j ++) {
////			if (!free[j]) cnt ++;
////			if (free[j] || ((i >> (cnt-1)) & 1)){
////				pur[j] = true;
////			}
////			else {
////				pur[j] = false;
////			}
////		}
////		ans = min(ans, solve());
////	}
//	cout << ans;
//	return 0;
//}

