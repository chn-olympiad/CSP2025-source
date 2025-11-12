//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 10, M = 5e6 + 3;
int n, m, k, cnt;
int fa[N];
ll c[12], a[12][N];
ll d[3010][3010];
struct node{
	int u, v;
	ll w;
} e[M];
void add(int u, int v, ll w) {
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
}
bool cmp(node x, node y) {
	return x.w < y.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void un(int u, int v) {
	fa[find(u)] = find(v);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = 4e9;
		}
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			for (int o = 1; o < j; o++) {
				d[j][o] = d[o][j] = min(d[o][j], a[i][j] + a[i][o] + c[i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			add(i, j, d[i][j]);
		}
	} 
	sort(e + 1, e + cnt + 1, cmp);
	ll sum = 0;
	for (int i = 1; i <= cnt; i++) {
		int u = e[i].u, v = e[i].v;
		ll w = e[i].w;
		if (find(u) != find(v)) {
			un(u, v);
			sum += w;
		}
	}
	printf("%lld\n", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
