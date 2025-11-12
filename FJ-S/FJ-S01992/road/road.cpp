#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	int x = 0, ff = 1;
	char c = getchar();
	while(!isdigit(c) && c != '-') c = getchar(); 
	if(c == '-') c = getchar(), ff = -1;
	while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
	return x * ff;
}
const int N = 1.1e4, M = 1.1e6;
const LL inf = 1e18;
int n, m, K, cnt;
struct edge{
	int x, y, z;
}e[M], E[N * 10];
int fa[N];
int getfa(int x){
	return fa[x] == x ? x : getfa(fa[x]);
}
bool flg[91];
bool merge(int x, int y){
//	cerr << x << ' ' << y << endl;
	if(x > n && !flg[x - n]) return 0;
	if(y > n && !flg[y - n]) return 0;
	x = getfa(x), y = getfa(y);
	if(x == y) return 0;
	fa[x] = y;
	return 1;
}
bool cmp(const edge& X, const edge& Y){
	return X.z < Y.z;
}
int head[N], to[M * 2], nxt[M * 2], tot;
LL w[M * 2], a[91][N], b[91];
void add_edge(int x, int y, int z){
	++tot;
	to[tot] = y;
	nxt[tot] = head[x];
	w[tot] = z;
	head[x] = tot;
}
#define pii pair<LL,int>
#define mk make_pair
priority_queue<pii> pq;
bool vis[N];
LL prim(int S){
	LL res = 0;
	for(int i = 1; i <= K; ++i)
		if(S & (1 << (i - 1)))
			flg[i] = 1, res += b[i];
		else
			flg[i] = 0;
	for(int i = 1; i <= n + K; ++i)
		vis[i] = 0;
	pq.push(mk(0, 1));
	while(!pq.empty()){
		int x = pq.top().second;
		LL d = -pq.top().first; pq.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		res += d;
		if(x <= n){
			for(int i = head[x]; i; i = nxt[i]){
				int y = to[i];
				if(!vis[y])
					pq.push(mk(-w[i], y));
			}
			for(int i = 1; i <= K; ++i)
				if(flg[i] && !vis[i + n])
					pq.push(mk(-a[i][x], i + n));
		}
		else{
			for(int i = 1; i <= n; ++i)
				if(!vis[i])
					pq.push(mk(-a[x - n][i], i));
		}
	}
	return res;
}
LL ans;
LL Kruskal(int S){
	LL res = 0;
//	int num = cnt;
	int comp = 0; 
	for(int i = 1; i <= K; ++i)
		if(S & (1 << (i - 1))){
			res += b[i];
			flg[i] = 1;
			comp --;
		}
		else
			flg[i] = 0;
	for(int i = 1; i <= n + K; ++i)
		fa[i] = i;
	for(int i = 1; i <= cnt; ++i){
//		cerr << i << ' ' << cnt << endl;
		if(merge(E[i].x, E[i].y)){
			res += E[i].z;
			++comp;
			if(res >= ans)
				return res;
			if(comp == n - 1)
				return res;
//			cerr << E[i].z << endl;
		}
	}
	return res;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); K = read(); 
	for(int i = 1; i <= m; ++i)
		e[i].x = read(), e[i].y = read(), e[i].z = read();
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	for(int i = 1; i <= m; ++i)
		if(merge(e[i].x, e[i].y)){
			add_edge(e[i].x, e[i].y, e[i].z);
			add_edge(e[i].y, e[i].x, e[i].z);
			E[++cnt] = e[i];
		}
	for(int i = 1; i <= K; ++i){
		b[i] = read();
		for(int j = 1; j <= n; ++j){
			a[i][j] = read();
			E[++cnt].x = i + n;
			E[cnt].y = j;
			E[cnt].z = a[i][j];
		}
	}
//	cerr << cnt << endl;
	sort(E + 1, E + cnt + 1, cmp);
	ans = inf;
//	cerr << Kruskal(1) << endl;
	for(int S = 0; S < (1 << K); ++S)
		ans = min(ans, Kruskal(S));
	cout << ans << '\n';
	return 0;
} 
