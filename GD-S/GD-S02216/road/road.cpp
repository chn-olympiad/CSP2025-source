#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n, m, k, tot, p[N];

struct Edge{
	int u, v, w;
}e[M << 1];

int find(int x){
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

bool cmp(Edge a, Edge b){
	return a.w < b.w;
}

void kruskal(){
	ll ans = 0, cnt = 0;
	sort(e + 1, e + 1 + tot, cmp);
	for(int i = 1; i <= n; ++i) p[i] = i;
	for(int i = 1; i <= tot; ++i){
		int u = find(e[i].u), v = find(e[i].v), w = e[i].w;
		if(u != v){
			p[v] = u;
			ans += w;
			++cnt;
			if(cnt == n - 1) break;
		}
	}
	cout << ans << "\n";
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; ++i){
		cin >> u >> v >> w;
		e[++tot] = {u, v, w};
	}
	if(k == 0){
		kruskal();
		return 0;
	}
	bool all0 = true;
	for(int i = 1, c; i <= k; ++i){
		cin >> c;
		if(c > 0) all0 = false;
		for(int j = 1, a; j <= n; ++j){
			cin >> a;
			if(a > 0) all0 = false;
		}
	}
	if(!all0){
		kruskal();
		return 0;
	}
	cout << "0\n";
	return 0;
}
