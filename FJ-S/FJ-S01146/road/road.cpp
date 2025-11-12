#include<bits/stdc++.h>
#define INF 1e17
#define int long long
using namespace std;

const int N = 1e4 + 10, M = 4e6 + 10, K = 11;

int T;

int n, m, k;
int res, t, ans;
struct Node{
	int u, v, w;
	
	bool operator <(const Node &b) const{
		return w < b.w;
	}
}G[M];

int c[K];
int cg[K][N];

int fa[N];
int find(int u){
	if(fa[u] == u) return fa[u];
	else return fa[u] = find(fa[u]);
}
set<int> vil;

bool is_in(int u){
	if(u <= n) return 1;
	if(vil.find(u - n) == vil.end()) return 0;
	return 1;
}

void MST(int _n){
	int cnt = 0;
	for(int i = 1; i <= _n; ++i) fa[i] = i;
	sort(G + 1, G + 1 + m);
	
	for(int i = 1; i <= m; ++i){
		int u = G[i].u, v = G[i].v;
		if(!is_in(u) || !is_in(v)) continue;
		
		u = find(u), v = find(v);
//		printf("%d - %d\n", u, v);
		if(u == v) continue;
		
		fa[u] = v, cnt++;
		t += G[i].w;
		
		if(cnt == _n - 1) break;
	}
	
//	printf("%lld\n", t);
}


int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return f * x;
}

void solve(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; ++i){
		G[i] = {read(), read(), read()};
	}
	
	//n + 1 ~ n + k
	for(int i = 1; i <= k; ++i){
		c[i] = read();
		for(int j = 1; j <= n; ++j) cg[i][j] = read();
		
	}
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= n; ++j)
			G[++m] = {j, n + i, cg[i][j]};
	
	ans = INF;
	for(int i = 0; i < (1 << k); ++i){
		t = 0;
		vil.clear();
		for(int j = 0; j < k; ++j)
			if((i >> j) & 1) vil.insert(j + 1), t += c[j + 1];
		
		MST(n + vil.size());
		
		ans = min(ans, t);
	}
	
	printf("%lld\n", ans);
	return;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	T = 1;
//	T = read();
	while(T--)
		solve();
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4

*/
