#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
int xxx, ans, tot, nn, n, m, k, c[11][10005], fa[N];
bool vv[15], v[15];
struct edge{
	int u, v, w;
};
set<edge> e; 
bool operator<(const edge &x, const edge &y) {
	return x.w < y.w;
}
int ffind(int x) {
	if (x == fa[x]) return x;
	else return fa[x] = ffind(fa[x]);
}

bool cmp(edge x, edge y) {
	return x.w < y.w;
}
int kruskal() {
	int cc = 0, res = 0; memset(vv, 0, sizeof(vv));
	for (int i = 1; i <= nn; i++) fa[i] = i;
	for (set<edge>::iterator it = e.begin(); it != e.end(); it++) {
		edge t = *it;
		if (cc == nn - 1) break;
		int x = ffind(t.u), y = ffind(t.v);
		if (x == y) continue;
		res += t.w;
		if (t.u > n && !vv[t.u - n]) vv[t.u - n] = 1, res += c[t.u - n][0];
		else if (t.v > n && !vv[t.v - n]) vv[t.v - n] = 1, res += c[t.v - n][0];
		fa[x] = y;
	}
	return res;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n >> m >> k; nn = n;
	for (int x, y, z, i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		edge t; t.u = x; t.v = y; t.w = z;
		e.insert(t);
	}
	ans = kruskal();
	for (int i = 1; i <= k; i++) {
		cin >> xxx;
		if (xxx > ans)
		  for (int j = 1; j <= n; j++) cin >> xxx;
		else {
			c[++tot][0] = xxx;
			for (int j = 1; j <= n; j++) cin >> c[tot][j];
		}
	}
	for (int i = 0; i <= (1 << tot) - 1; i++) { 
		for (int j = 1; (1 << (j - 1)) <= i; j++) { 
			if (v[j] && (i & (1 << (j - 1)))) continue;
			if (v[j] && !(i & (1 << (j - 1)))) {
				nn--;
				for (int k = 1; k <= n; k++) {
					edge t; t.u = n + j; t.v = k; t.w = c[j][k];
					set<edge>::iterator it = e.find(t);
					e.erase(it);
					t.u = k; t.v = n + j;
					it = e.find(t);
					e.erase(it);
				}
				v[j] = 0;
			}
			else {
				nn++;
				for (int k = 1; k <= n; k++) {
					edge t; t.u = n + j; t.v = k; t.w = c[j][k];
					e.insert(t);
					t.u = k; t.v = n + j;
					e.insert(t);
				}
				v[j] = 1;
			}
		}
		ans = min(ans, kruskal());
	}
	cout << ans;
	return 0;
} 


