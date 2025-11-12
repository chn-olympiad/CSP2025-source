#include<bits/stdc++.h>
#define int long long
#define mk make_pair
using namespace std;
int read();
const int N = 1e4 + 10;
const int M = 1e6 + 10;
int c[15], a[15][N], fa[N];
struct Edge {
	int u, v, w, w1;
} e[M];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
//	if (k == 0) {
	for (int i = 1; i <= m; i++) {
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	sort(e + 1, e + m + 1, cmp);
	int ans = 0;
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		int u = find(e[i].u);
		int v = find(e[i].v);
		if (u != v) {
			fa[u] = v;
			ans += e[i].w;
			tot++;
		}
		if (tot == n - 1) {
			cout << ans;
			return 0;
		}
	}
//	} else {
//		vector<pair<int, int>> e1[N];
//		for (int i = 1; i <= m; i++) {
//			int u = read(), v = read(), w = read();
//			e1[u].push_back(mk(v, w));
//			e1[v].push_back(mk(u, w));
//		}
//		for (int i = 1; i <= k; i++) {
//			c[i] = read();
//			for (int j = 1; j <= n; j++) {
//				a[i][j] = read();
//			}
//		}
//		int ans = 0x3f3f3f3f;
//		vector<pair<int, int>> e2[N];
//		for (int i = 1; i <= k; i++) {
//			for (int i = 1; i <= n; i++) {
//				fa[i] = i;
//			}
//			int cnt = c[i], tot = 0;
//			for (int j = 1; j <= m; j++) {
//				e[j].w1 = min(e[j].w, a[i][e[j].u] + a[i][e[j].v]);
//			}
//			sort(e + 1, e + m + 1, cmp);
//			for (int j = 1; j <= m; j++) {
//				int u = find(e[j].u);
//				int v = find(e[j].v);
//				if (u != v) {
//					cout << j << " ";
//					fa[u] = v;
//					cnt += e[j].w1;
//					tot++;
//				}
//				if (tot == n - 1) {
//					break;
//				}
//			}
//			cout << i << " " << cnt << endl;
//			ans = min(ans, cnt);
//		}
//		cout << ans;
//}
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') {
			Cf = -1;
		}
	}
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Cf * Ca;
}