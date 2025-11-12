#include <cstdio>
#include <queue>
#define ll long long
#define pii pair<int, int>
using namespace std;
constexpr int N = 10025, M = 1010050, K = 15;
vector<pii> e[N];

int n, m, k, x, y, u, v;
int g[K], z, d[N], w;
ll ans = 1e18;
int er[N];	//加入答案的边权 
int tn[K][N];
bool vis[N], cg[N], flg;

inline void ins(int x, int y){
	e[x].push_back({z, y});
}
inline void prm(ll s){
	int sm = 0;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	for(register int i=1; i<=n+k; i++)	d[i] = 1e9, vis[i] = 0, er[i] = 0;
	q.push({0, 1});
	d[1] = 0;
	while(q.size()){
		u = q.top().second, q.pop();
		if(vis[u])	continue;
		s += er[u], vis[u] = 1;
		if(u <= n)	sm++;
		if(sm == n)	break;
		if(s >= ans)	return;
		for(register pii i:e[u]){
			v = i.second, w = i.first;
			if(!vis[v] && d[v] > w){
				d[v] = w, er[v] = w;
				q.push({w, v});
			}
		}
	}
	ans = min(ans, s);
}	//最小生成树 O(n logn) <= 10^5
inline void dfs(int x, ll s){
	if(s >= ans)	return;
	if(x > k+n){
		prm(s);
		return;
	}
	for(register int i=1; i<=n; i++){
		z = tn[x-n][i];
		ins(i, x), ins(x, i);
	}
	dfs(x+1, s+g[x-n]);
	for(register int i=1; i<=n; i++){
		e[i].pop_back(), e[x].pop_back();
	}
	if(flg)	dfs(x+1, s);	//性质A 
}	//搜索枚举 O(2^k) <= 1024 
//10^5 * 1024 = 10^8 TLE?????
template <typename _Tp>
inline void rd(_Tp& inp){
	char c;
	c = getchar();
	inp = 0;
	while(c>='0' && c<='9'){
		inp *= 10, inp += c-'0';
		c = getchar();
	}
}	//快读 
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	rd(n), rd(m), rd(k);
	for(register int i=1; i<=m; i++){
		rd(x), rd(y), rd(z);
		ins(x, y), ins(y, x);
	}
	for(register int i=1; i<=k; i++){
		e[i].reserve(n);
		rd(g[i]);
		if(g[i])	flg = 1;
		for(register int j=1; j<=n; j++)	rd(tn[i][j]);
	}
	for(register int i=1; i<=n; i++)	cg[i] = 1, e[i].reserve(k);
	dfs(n+1, 0);
	printf("%lld", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}
