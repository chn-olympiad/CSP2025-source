#include <bits/stdc++.h>

using namespace std;

inline
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ '0');
		ch = getchar();
	}
	return x * f;
}

const int N = 1e6 + 1e5 + 7, M = 1e4 + 17;

int n, m, mm, k, c[17], a[17][M], chs[17], fa[M];

long long ans;

struct node {
	int u, v, w, id;
}e[N];

inline
bool cmp(node x, node y) {
	return x.w < y.w;
}

inline
bool cmp1(node x, node y) {
	return x.id < y.id;
}

inline
int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

inline
long long solve() {
	long long ans = 0;
	sort(e + 1, e + 1 + mm, cmp);
	for (int i = 1; i <= mm; i++) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y) {
			fa[y] = x;
			ans += e[i].w;
		}
	}
	sort(e + 1, e + 1 + mm, cmp1);
	return ans;
}

inline
void dfs(int x) {
	if (x > k) {
		int res = 0;
		for (int i = 1; i <= n + k; i++) fa[i] = i;
		mm = m;
		for (int i = 1; i <= k; i++) {
			if (chs[i] == 1) {
				res += c[i];
				for (int j = 1; j <= n; j++) {
					mm++;
					e[mm] = {n + i, j, a[i][j], n + 1};
				}
			}
		}
		if (res > ans) return ;
		ans = min(ans, solve() + res);
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		chs[x] = i;
		dfs(x + 1);
	} 
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) e[i].u = read(), e[i].v = read(), e[i].w = read(), e[i].id = i;
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) a[i][j] = read();
	}
	ans = 2e18;
	dfs(1);
	cout << ans << '\n';
	return 0;
}
