#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n, m, k, ans = 1e18;
struct node {
	int u, v, w;
} b[1000005], b_[2000005];
int tot;
int c[15], a[15][10005];
bool qwq = 0;
//vector <edge> sons[10005];
//void add(int u, int v, int w) {
//	sons[u].push_back({v, w});
//}
bool cmp(node x, node y) {
	return x.w < y.w;
}

int fa[10005];
int Find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}
int kru() {
	int res = 0, cnt = 0;
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	sort(b_ + 1, b_ + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		int u = b_[i].u, v = b_[i].v, w = b_[i].w;
		u = Find(u);
		v = Find(v);
		if (u != v) {
			fa[u] = v;
			res += w;
			cnt++;
		}
	}
	return res;
}

int gz[15];
void dfs(int x) {
	if (x == (k + 1)) {
		int xans = 0;
		for (int i = 1; i <= m; i++) {
			b_[i] = b[i];
		}
		tot = m;
		for (int i = 1; i <= k; i++) {
			if (gz[i]) {
				for (int j = 1; j <= n; j++) {
					b_[++tot] = {i + n, j, a[i][j]};
				}
				xans += c[i];
			}
		}
		xans += kru();
		ans = min(ans, xans);
		return ;
	}
	if (qwq) {
		gz[x] = 0;
		dfs(x + 1);
	}
	gz[x] = 1;
	dfs(x + 1);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> b[i].u >> b[i].v >> b[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) qwq = 1;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	dfs(1);
	
	cout << ans << endl;
	return 0;
}
