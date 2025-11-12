#include<bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 5;
long long n, m, k, u[N], v[N], w[N], c[15], a[15][10005], ans;
long long f[10005];

struct edge{
	int u, v, w;
}e[2 * N];

bool cmp(edge a, edge b){
	return a.w < b.w;
}

int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

void merge(int x, int y){
	f[find(y)] = find(f[x]);
}

void kruskal(){
	for(int i = 1; i <= n; i++) f[i] = i;
	sort(e + 1, e + 2 * m + 1, cmp);
	for(int i = 1; i <= 2 * m; i++){
		int x = e[i].u, y = e[i].v;
		if(find(x) != find(y)){
			merge(x, y);
			ans += e[i].w;
		}
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
	}
	for(int i = 1; i <= k; i++){
		scanf("%lld", &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%lld", &a[i][j]);
		}
	}
	for(int i = 1; i <= m; i++){
		e[i].u = u[i];
		e[i].v = v[i];
		e[i].w = w[i];
		e[i + m].u = v[i];
		e[i + m].v = u[i];
		e[i + m].w = w[i];
	}
	kruskal();
	printf("%lld", ans);
	return 0;
}
