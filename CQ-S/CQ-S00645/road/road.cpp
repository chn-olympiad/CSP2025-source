#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1e6 + 1e5 + 10;
const int K = 15;
int n, m, k, tot, c[15], ans;
bool bui[K];
struct Edge {
	int u, v, w, vil;
}e[M];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
int f[N];
int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		tot++;
		cin >> e[tot].u >> e[tot].v >> e[tot].w;
		if(e[tot].u > e[tot].v) swap(e[tot].u, e[tot].v);
	}
//	for(int i = 1; i <= k; i++) {
//		cin >> c[i];
//		for(int j = 1; j <= n; j++) {
//			int qwe = 0;
//			cin >> qwe;
//			tot++;
//			e[tot].u = i + n; e[tot].v = j; e[tot].w = qwe + c[i];
//			if(e[tot].u > e[tot].v) swap(e[tot].u, e[tot].v);
//			e[tot].vil = i;
//		}
//	}
	sort(e + 1, e + tot + 1, cmp);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= tot; i++) {
		if(find(e[i].u) != find(e[i].v)) {ans += e[i].w; f[find(e[i].v)] = find(e[i].u);}
	}
	cout << ans;
	return 0;
}

