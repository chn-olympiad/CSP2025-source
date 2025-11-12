#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
int n, m, k, u, v, w, e, p[maxn], siz[maxn], c[11][maxn]; ll ans;
struct node {
	int u, v, w;
	friend bool operator < (node a, node b) {
		return a.w < b.w;
	}
} E[maxn], E2[maxn], tmp[maxn];
int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}
void merge(int x, int y) {
	x = get(x); y = get(y);
	if (x == y) return;
	if (siz[x] > siz[y]) swap(x, y);
	p[x] = y; siz[y] += siz[x];
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= n; i++) p[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++) {
		if (get(E[i].u) != get(E[i].v)) {
			merge(E[i].u, E[i].v);
			E2[++e] = E[i];
			ans += E[i].w;
		}
	}
	for (int S = 0; S < (1 << k); S++) {
		int e2 = e;
		for (int i = 1; i < n; i++) tmp[i] = E2[i];
		ll sum = 0;
		for (int i = 1; i <= k; i++) {
			if (S & (1 << (i - 1))) {
				for (int j = 1; j <= n; j++) {
					tmp[++e2] = {i + n, j, c[i][j]};
				}
				sum += c[i][0];
			}
		}
		for (int i = 1; i <= n + k; i++) p[i] = i, siz[i] = 1;
		sort(tmp + 1, tmp + e2 + 1);
		for (int i = 1; i <= e2; i++) {
			if (get(tmp[i].u) != get(tmp[i].v)) {
				merge(tmp[i].u, tmp[i].v);
				sum += tmp[i].w;
			}
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
	return 0;
} 
/*
先跑最小生成树，然后枚举乡镇的集合，共 (n - 1) + (nk) 条边做最小生成树
时间复杂度 O(1000 nk log nk) 应该可以过绝大部分数据 ，期望得分 80pts 
*/
