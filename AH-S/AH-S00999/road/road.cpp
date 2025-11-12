#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5, M = 2e6 + 5;

int n, m, k, f[N], flag[N], x, y;
long long ans = 1e18, res, cnt, c[N];
struct edge {
	int u, v;
	long long w;
} e[M];

int cmp(edge x, edge y) {
	return x.w < y.w;
}

int fnd(int x) {
	if (x != f[x])	return f[x] = fnd(f[x]);
	return x;
}

long long calc() {
	res = 0, cnt = 0;
	for (int i = 1; i <= n + k; i++)	f[i] = i;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		if (!flag[v] || !flag[u])	continue ;
		long long w = e[i].w;
		x = fnd(u), y = fnd(v);
		if (x != y) {
			f[x] = y;
			res += w;
			cnt++;
		}
		if (res >= ans)	return res;
		if (cnt >= n + k - 1)	return res;
	}
	return res;
}

void dfs(int step, long long cst) {
	if (step > k) {
		ans = min(ans, calc() + cst);
		return ;
	}
	flag[step + n] = 1;
	dfs(step + 1, cst + c[n + step]);
	if (c[n + step] != 0) {
		flag[step + n] = 0;
		dfs(step + 1, cst);
	}
	return ;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[n + i]);
		for (int j = 1; j <= n; j++) {
			m++;
			scanf("%lld", &e[m].w);
			e[m].u = n + i;
			e[m].v = j;
		}
	}
	
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if (e[i].u > e[i].v) {
			swap(e[i].u, e[i].v);
		}
	}
	for (int i = 1; i <= n; i++)	flag[i] = 1;
	dfs(1, 0);
	
	printf("%lld\n", ans);
	
	return 0;
}
