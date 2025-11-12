#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
const int M = 1e6 + 5;

int n, m, tot, k, f[N];
ll c[11], a[11][N];

struct edge{
	int u, v;
	ll w;
} e[M * 11];

bool cmp(edge a, edge b){
	return a.w < b.w;
}

int find(int k){
	return f[k] == k ? k : f[k] = find(f[k]);
}

void kruscal(){
	int kk = 0;
	ll ans = 0;
	for(int i = 1; i <= tot; ++i){
		int u = e[i].u, v = e[i].v;
		ll w = e[i].w;
		if(find(u) != find(v)){
			f[find(u)] = find(v);
			ans += w;
			if(++kk == n - 1) break;
		}
	}
	printf("%lld", ans);
}

void solve_A(){
	for(int i = 1; i <= k; ++i){
		for(int j = 1; j <= n; ++j){
			for(int o = j + 1; o <= n; ++o){
				e[++tot].u = j;
				e[tot].v = o;
				e[tot].w = a[i][j] + a[i][o];
			}
		}
	}
	sort(e + 1, e + 1 + tot, cmp);
	for(int i = 1; i <= n; ++i) f[i] = i;
	kruscal();
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool fA = 1;
	scanf("%d%d%d", &n, &m, &k); tot = m;
	for(int i = 1; i <= m; ++i) scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	for(int i = 1; i <= k; ++i){
		scanf("%lld", &c[i]);
		if(c[i]) fA = 0;
		for(int j = 1; j <= n; ++j){
			scanf("%lld", &a[i][j]);
		}
	}
	if(k != 0 && fA){
		solve_A();
		return 0;
	}
	for(int i = 1; i <= n; ++i) f[i] = i;
	sort(e + 1, e + 1 + m, cmp);
	kruscal();
	return 0;
} 

/*
3 3 0
1 2 1
2 3 1
1 3 2
*/
