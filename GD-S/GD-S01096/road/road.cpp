#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5, K = 15, M = 1e6+5;
int n, m, k, c[K], a[K][N], it, fa[N], x[N];
long long ans;
struct node {
	int f, to, va;
} e[M];
bool cmp(node x, node y) {
	return x.va<y.va;
}
int Find(int root) {
	if(fa[root]==root) return root;
	return fa[root] = Find(fa[root]);
}
void merge(int x, int y) {
	int fx = Find(x), fy = Find(y);
	if(fx!=fy) fa[fy] = fx;
}
bool check() {
	int x = Find(1);
	for(int i=2; i<=n; i++)
		if(Find(i)!=x) return false;
	return true;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++) fa[i] = i;
	for(int i=1, u, v, w; i<=m; i++) {
		scanf("%d %d %d", &u, &v, &w);
		it++; e[it].f = u, e[it].to = v, e[it].va = w;
		it++; e[it].f = v, e[it].to = u, e[it].va = w;
	}
	for(int i=1; i<=k; i++) {
		scanf("%d", &c[i]);
		for(int j=1; j<=n; j++) scanf("%d", &x[j]);
		for(int j=1; j<=n; j++) {
			for(int k=1; k<=n; k++) {
				it++; e[it].f = j, e[it].to = k, e[it].va = x[j]+x[k]+c[i];
				it++; e[it].f = k, e[it].to = j, e[it].va = x[j]+x[k]+c[i];
			}
		}
	}
	sort(e+1, e+it+1, cmp);
	for(int i=1; i<=it; i++) {
		if(!check()) {
			int x = e[i].f, y = e[i].to, z = e[i].va;
			if(Find(x)!=Find(y)) {
				merge(x, y);
				ans += z;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
