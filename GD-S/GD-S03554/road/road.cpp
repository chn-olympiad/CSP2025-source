#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

constexpr int K = 15, N = 1e4 + K + 5, M = 1e6 + N * K + 5;

int n, m, k;

int a[K][N];
int c[K]; 

struct edge {
	int u, v, w;
	bool operator<(const edge &b) const {return w < b.w;}
} e[M], e2[M];

int fa[N];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void init() {iota(fa + 1, fa + 1 + n + k, 1);}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	fa[x] = y;
}

ll initMST() {
	ll res = 0;
	sort(e2 + 1, e2 + 1 + m);
	int m2 = 0;
	init();
	for (int i = 1; i <= m; i++) {
		int u = e2[i].u, v = e2[i].v, w = e2[i].w;
		if (find(u) != find(v)) {
			merge(u, v);
			res += w;
			e[++m2] = {u, v, w};
		}
	}
	
	m = n - 1;
	
	return res;
}

ll MST(int msk) {
	ll res = 0;
	int tot = m;
	for (; msk; msk -= msk & -msk) {
		int i = __lg(msk & -msk) + 1;
		res += c[i];
		for (int j = 1; j <= n; j++)
			e[++tot] = {n + i, j, a[i][j]};
	}
	
	sort(e + 1, e + 1 + tot);
	init();
	for (int i = 1; i <= tot; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) != find(v)) {
			merge(u, v);
			res += w;
		}
	}
	
	return res;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	bool A = 1; 
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e2[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		A &= c[i] == 0; bool ok = 0; 
		for (int j = 1; j <= n; j++) 
			cin >> a[i][j], ok |= a[i][j] == 0;
		A &= ok;
	}
	
	ll ans = initMST();
	
	if (A) {
		cout << MST((1 << k) - 1) << "\n";
		return 0;
	}

	for (int i = 1; i < 1 << k; i++)
		ans = min(ans, MST(i));
		
	cout << ans << "\n";
	return 0;
}
