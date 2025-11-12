#include<bits/stdc++.h>
#define int long long
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define per(i, j, k) for(int i = (j); i >= (k); --i)
#define repl(i, j, k, l) for(int i = (j); (k); i = (l))
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii pair<int, int>
#define MP pair<int, int>
#define EB emplace_back
#define PB push_back
#define lson p << 1
#define rson p << 1 | 1
#define fir first
#define sec second
using namespace std;
const int MXSIZE = 1 << 20;
char *P1(0), *P2(0), BUFFER[MXSIZE];
#define gtc() (P1 == P2 && (P2 = (P1 = BUFFER) + fread(BUFFER, 1, MXSIZE, stdin), P1 == P2) ? EOF : *P1++)
#define pc putchar
inline int R(){
	int x; char c; bool f = 0;
	while(!isdigit(c = gtc())) if(c == '-') f = 1;
	x = c ^ '0';
	while(isdigit(c = gtc())) x = (x << 3) + (x << 1) + (c ^ '0');
	return f ? ~x + 1 : x;
}
inline void O(int x){
	if(x < 0) pc('-'), x = -x;
	if(x < 10) pc(x + '0');
	else O(x / 10), pc(x % 10 + '0');
}
inline void out(int x, int type = 2){
	O(x);
	if(type == 1) pc(' ');
	if(type == 2) pc('\n');
}
inline void OI(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}
const int N = 1e4 + 10;
const int M = 1e6 + 10;
//struct E{
//	int to, nxt, w;
//}e[N << 1];
int a[15][N], c[15], n, m, k;
//vector<int> a[15];
//int head[N << 1], tot, f[N][20], dis[N], dep[N], idx2[15][N], idx[15];
//inline void add(int x, int y, int w){
//	e[++tot].to = y;
//	e[tot].w = w;
//	e[tot].nxt = head[x];
//	head[x] = tot;
//}
//void dfs(int x, int fa){
//	f[x][0] = fa; dep[x] = dep[fa] + 1;
//	rep(i, 1, 16) f[x][i] = f[f[x][i - 1]][i - 1];
//	repl(i, head[x], i, e[i].nxt){
//		int v = e[i].to, w = e[i].w;
//		if(v == fa) continue;
//		dis[v] = dis[x] + w;
//		dfs(v, x);
//	}
//}
//int lca(int u, int v){
//	if(dep[u] < dep[v]) swap(u, v);
//	per(i, 16, 0) if(dep[f[u][i]] >= dep[v]) u = f[u][i];
//	if(u == v) return u; 
//	per(i, 16, 0) if(f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
//	return f[u][0];
//}
struct Ed{
	int u, v, w;
}ed[M], ed2[N];
int fa[N], cnt;
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
bool cmp(Ed x, Ed y){return x.w < y.w;}
//bool cmp2(int x, int y){return c[x] < c[y];}
//bool cmp3(Ed x, Ed y){return x.w > y.w;}
//int tmp[N];
//bool cmp4(int x, int y){return tmp[x] < tmp[y];}
inline void solve(){
	n = R(), m = R(), k = R();
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) ed[i] = {R(), R(), R()};
	sort(ed + 1, ed + m + 1, cmp);
	int ans = 0;
	rep(i, 1, m){
		int u = ed[i].u, v = ed[i].v, w = ed[i].w;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		fa[fv] = fu, ans += w; 
//		ed2[++cnt] = {u, v, w};
//		add(u, v, w); add(v, u, w);
	}
	rep(i, 1, k){
		c[i] = R();
		rep(j, 1, n) a[i][j] = R();
//		sort(idx2[i] + 1, idx2[i] + n + 1, cmp4);
	}
//	if(!k) 
		return out(ans);
//	dfs(1, 0);
////	sort(ed2 + 1, ed2 + cnt + 1, cmp3);
//	sort(idx + 1, idx + k + 1, cmp2);
//	int tot2 = 0, cnt1 = 0, cnt2 = 0;
//	rep(id, 1, k){
//		int i = idx[id];
//		cnt1 = 1;
//		tot2 += c[i]; tot2 += a[i][idx2[i][1]];
//		rep(j, 2, n){
//			int now = a[i][idx2[i][j]];
////			tot2 += now;
//			int u = idx2[i][cnt1], v = idx2[i][j];
//			int mx = 0, lc = lca(u, v);
//			for(int l = u; f[l][0] != lc ; l = f[l][0]) mx = max(mx, dis[l] - dis[f[l][0]]);
//			for(int l = v; f[l][0] != lc ; l = f[l][0]) mx = max(mx, dis[l] - dis[f[l][0]]);
//			if(cnt2 == 0 && )
//		}
//	}
}
signed main(){
	 OI();
	// int cas = R();
	int T = 1;
	// T = R();
	while(T--) solve();
	return 0;
}


