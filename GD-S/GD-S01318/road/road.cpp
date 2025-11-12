#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, l, r) for(int i = l; i <= r; i++)
#define per(i, l, r) for(int i = l; i >= r; i--)
ll read(){
	ll res = 0, flg = 1; char c = getchar();
	for(; c > '9' || c < '0'; c = getchar()) if(c == '-') flg = -flg;
	for(; c >= '0' && c <= '9'; c = getchar()) res = (res << 3) + (res << 1) + c - '0';
	return res * flg;
}
void write(ll x, char c = '\n'){
	if(x < 0) putchar('-'), x = -x;
	static int stk[35]; int top = 0;
	do { stk[top++] = x % 10; x /= 10; } while(x);
	while(top) { putchar(stk[--top] + '0'); }
	putchar(c);
}

const int N = 1e4 + 5;
const int mxS = (1 << 10) + 1;
int n, m, k;

struct edge{
	int v;
	ll w;
};
vector<edge> e[N];
vector<int> tr[N];
vector<pair<pair<int, int>, ll>> edges;

ll dp[N][mxS];
ll W[10][N];
int c[10];
ll mn_w[N];
ll inf;

int dfn[N], rdfn[N], dfncnt = 0;
bool vis[N];
void dfs(int u){
	if(vis[u]) return;
	rdfn[++dfncnt] = u;
	dfn[u] = dfncnt;
	vis[u] = 1;
	for(int i = 0, siz = tr[u].size(); i < siz; i++){
		int v = tr[u][i];
		dfs(v);
	}
}

struct DSU{
	int fa[N];
	void init(int n){
		rep(i, 1, n) fa[i] = i;
	}
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return;
		fa[x] = y;
	}
} DSU;

namespace SUB_A{
	void solve(){
		rep(j, 0, k - 1){
			rep(i, 1, n){
				edges.push_back({{n + 1 + j, i}, W[j][i]});
			}
		}
		sort(edges.begin(), edges.end(), [](pair<pair<int, int>, ll> x, pair<pair<int, int>, ll> y){
			return x.second < y.second;
		});
		int cnt = 1;
		ll ans = 0;
		DSU.init(n + k);
		for(pair<pair<int, int>, ll> side : edges){
			if(cnt == n + k) break;
			int u = side.first.first, v = side.first.second; ll w = side.second;
			if(DSU.find(u) == DSU.find(v)) continue;
			cnt++;
			DSU.merge(u, v);
			ans += w;
		}
		write(ans);
	}
}

void solve(){
	n = read(), m = read(), k = read();
	
	memset(mn_w, 0x3f, sizeof(mn_w)); inf = mn_w[1];
	rep(i, 1, m){
		int u = read(), v = read();
		ll w = read();
		e[u].push_back({v, w});
		e[v].push_back({u, w});
		edges.push_back({{u, v}, w});
	}
	
	bool flg = 1;
	rep(j, 0, k - 1){
		c[j] = read();
		if(c[j] != 0) flg = 0;
		bool flg2 = 0;
		rep(i, 1, n){
			W[j][i] = read();
			if(W[j][i] == 0) flg2 = 1;
		}
		if(!flg2) flg = 0;
	}
	if(flg || k == 0){
		SUB_A::solve();
		return;
	}

	sort(edges.begin(), edges.end(), [](pair<pair<int, int>, ll> x, pair<pair<int, int>, ll> y){
		return x.second < y.second;
	});
	int cnt = 1;
//	dfn[1] = ++dfncnt, rdfn[dfncnt] = 1;
	DSU.init(n);
	for(pair<pair<int, int>, ll> side : edges){
		if(cnt == n) break;
		int u = side.first.first, v = side.first.second; ll w = side.second;
		if(DSU.find(u) == DSU.find(v)) continue;
		cnt++;
		DSU.merge(u, v);
		tr[u].push_back(v), tr[v].push_back(u);
//		cerr << u << ' ' << v << "---\n";
	}
	
	dfs(1);
//	rep(i, 1, n) fprintf(stderr, "i: %d, rdfn: %d\n", i, rdfn[i]);

	
	rep(i, 0, m - 1){
		int u = edges[i].first.first, v = edges[i].first.second;
		ll w = edges[i].second;
		if(dfn[u] < dfn[v]) mn_w[v] = min(mn_w[v], w);
		else mn_w[u] = min(mn_w[u], w);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	dp[1][0] = 0;
	rep(S, 1, (1 << k) - 1){
		dp[1][S] = 0;
		rep(j, 0, k - 1){
			if(S & (1 << j)){
				dp[1][S] += W[j][rdfn[1]] + c[j];
			}
		}
//		fprintf(stderr, "i: 1 S: %d dp: %lld \n", S, dp[1][S]);
	}
	
	rep(i, 2, n){
		int u = rdfn[i];
		rep(S, 0, (1 << k) - 1){
			dp[i][S] = min(inf, dp[i - 1][S] + mn_w[u]);
			rep(j, 0, k - 1){
				if(S & (1 << j)){
					dp[i][S] = min(dp[i][S], dp[i - 1][S] + W[j][u]);
				}
			}
			
			rep(j, 0, k - 1){
				if(S & (1 << j)){
					dp[i][S] = min(dp[i][S], dp[i][S ^ (1 << j)] + c[j] + W[j][u]);
				}
			}
			
//			fprintf(stderr, "i: %d S: %d dp: %lld \n", i, S, dp[i][S]);
		}
	}
	ll ans = inf;
	rep(S, 0, (1 << k) - 1){
		ans = min(ans, dp[n][S]);
	}
	write(ans);
}
/*
in : 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 2
1 2 6
2 3 5
2 4 4
3 4 7
1 1 4 8 2
100 1 4 3 2

out : 13
*/
signed main(){
	#ifndef MY_JUDGE
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
	#endif
	
	#ifdef MY_JUDGE
//		freopen("road3.in", "r", stdin);
//		freopen("my.out", "w", stdout);
	#endif
	solve();
	return 0;
}

