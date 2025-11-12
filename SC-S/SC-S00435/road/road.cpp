#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define lowbit(x) (x) & (-x)
template<typename T> void read(T &x) {
	T f = 1; x = 0; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit((ch))) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
}
const int M = 1e7 + 5, N = 5e4 + 5, K = 10 + 5;
int n, m, k;
ll c[K], bw[K][N];
struct edge{
	int to, nxt, typ;
	ll w;
}e[M << 1];
int cnt, head[N], vis[N], ok[N];
inline void add(int u, int v, ll w) {
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
	return;
}
struct node{
	int p, d;
	bool operator <(const node &x) const {
		return x.d < d;
	}
};
struct nnode{
	int u, v; ll w;
	bool operator <(const nnode &x) const {
		return x.w < w;
	}
}g[M], nw[K][N];
ll ans = 0x7f7f7f7f7f7f7f7f;
void prim(ll base) {
	priority_queue<node> q;
	for(int i = 1; i <= n; i++) vis[i] = 0;
	q.push({1, 0});
	int ct = 0;
	ll res = base;
	while(!q.empty() && ct <= n) {
		node hd = q.top();
		q.pop();
		int u = hd.p; ll d = hd.d;
		if(vis[u]) continue;
		vis[u] = 1;
		ct++; res += d;
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].to, w = e[i].w;
			q.push({v, w});
		}
	}
	ans = min(ans, res);
	return;
}
int f[N];
int find(int x) {
	if(x != f[x]) return f[x] = find(f[x]);
	return f[x];
}
void merge(int u, int v) {
	int fx = find(u), fy = find(v);
	if(f[fx] != f[fy]) f[fx] = f[fy];
}
void dfs(int p, int yn, ll fy) {
	ok[p] = yn;
	if(p == k) {
		if(!fy) return;
		priority_queue<nnode> q;
		ll res = 0, ct = 0;
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i <= k; i++) {
			if(ok[i]) {
				for(int j = 1; j <= n; j++) {
					q.push(nw[i][j]);
				}
			}
		}
		for(int i = 1; i <= m; i++) q.push(g[i]);
		while(!q.empty() && ct < n - 1) {
			if(f[q.top().u] == f[q.top().v]) {
				q.pop();
				continue;
			}
			res += q.top().w;
			merge(q.top().u, q.top().v);
			ct++;
//			cout << res << " ";
			q.pop();
		}
//		cout << endl;
//		cout << fy + res << endl;
		ans = min(ans, fy + res);
		return;
	}
	dfs(p + 1, 0, fy);
	dfs(p + 1, 1, fy + c[p + 1]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 1; i <= m; i++) {
		ll u, v, w;
		read(u), read(v), read(w);
		g[i].u = u, g[i].v = v, g[i].w = w;
		add(u, v, w), add(v, u, w);
	}
	for(int i = 1; i <= k; i++) {
		read(c[i]);
		for(int j = 1; j <= n; j++) read(bw[i][j]);
		sort(bw[i] + 1, bw[i] + n + 1);
		priority_queue<nnode> q;
		for(int r = 1; r <= n; r++) {
			for(int j = r + 1; j <= n; j++) {
				q.push({r, j, bw[i][r] + bw[i][j]});
			}
		}
		int tmp = 0;
		while(!q.empty() && tmp <= n - 1) {
			nw[i][++tmp] = q.top();
			q.pop();
		}
	}
	prim(0);
	dfs(0, 1, 0);
	printf("%lld\n", ans);
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/