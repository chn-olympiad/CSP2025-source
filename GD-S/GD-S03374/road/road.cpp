#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long ;
const int N = 10105, M = 1000005, SIZ = N * 2;
const ll inf = 1e17;

inline ll read(){
	ll ret = 0, sym = 1;  char c = getchar();
	while(!(c >= '0' && c <= '9'))  {if(c == '-') sym = -1;  c = getchar();}
	while(c >= '0' && c <= '9')  {ret = ret * 10ll + c - '0'; c = getchar();}
	return ret * sym;
}

void print(ll x, char inter){
	if(x < 0) x = -x, putchar('-');
	if(x > 9) print(x / 10ll, '\0');
	putchar(x % 10ll + '0');
	if(inter)  putchar(inter);
}

int n, m, K;
ll a[15][N];
ll c[N];

struct dedge{int u, v; ll w;};

struct Uni_Set{
	int fa[SIZ];
	inline int fnd(int x) {return fa[x] = (fa[x] == x? x: fnd(fa[x]));}
	inline void uni(int x, int y) {fa[fnd(x)] = fnd(y);}   //x ---> y
	inline void init(int siz)  {for(int i=1; i<=siz; ++ i)  fa[i] = i;}
};

struct Kruskal_Rebuild_Tree{
	int n=0, rt = 0;
	ll v[SIZ];
	struct edge{int to, nxt;} e[SIZ];
	int cnte = 0;
	int head[SIZ];
	void add(int u, int v)  {e[++ cnte] = {v, head[u]}; head[u] = cnte;}
	int getnw() {return ++ n;}

	int dep[SIZ];
	int fa[SIZ][30];
	void dfs(int x, int father){
		dep[x] = dep[father] + 1;
		fa[x][0] = father;
		for(int i=1; i<=20; ++ i){
			fa[x][i] = fa[fa[x][i-1]][i-1];
		} 
		for(int i=head[x]; i; i=e[i].nxt){
			dfs(e[i].to, x);
		}  
	}

	int lca(int x, int y){
		if(dep[x] < dep[y])  swap(x, y);
		int dist = dep[x] - dep[y];
		for(int i=0; dist; (dist>>=1), (++ i))  if(dist & 1)  x = fa[x][i];
		if(x == y)  return x;
		for(int i=20; i>=0; -- i)  if(fa[x][i] ^ fa[y][i])  x = fa[x][i], y = fa[y][i];
		return fa[x][0];
	}
};

struct Tree{
	int n=0, m=0;
	dedge e[N];
	Uni_Set s;
	
	ll kruskal(Kruskal_Rebuild_Tree &k){
		k.n = n;
		ll ret = 0;
		s.init(2*n);
		sort(e+1, e+m+1, [](dedge i, dedge j)->bool{return i.w < j.w;});
		for(int i=1; i<=m; ++ i){
			int u = e[i].u, v = e[i].v;
			ll w = e[i].w;
			int nw = k.getnw();
			k.add(nw, s.fnd(u));  
			k.add(nw, s.fnd(v));
			k.v[nw] = e[i].w;
			k.rt = nw;
			s.uni(s.fnd(u), nw);
			s.uni(s.fnd(v), nw);
		}
		return ret ;
	}
};

struct Ori_Graph{
	dedge e[M];
	Uni_Set s;
	
	ll kruskal(Tree &t){   //找到原图的最小生成树
		t.n = n, t.m = 0;
		ll ret = 0;
		s.init(n);
		sort(e+1, e+m+1, [](dedge i, dedge j)->bool{return i.w < j.w;});
		for(int i=1; i<=m; ++ i){
			int u = e[i].u, v = e[i].v;
			ll w = e[i].w;
			if(s.fnd(u) ^ s.fnd(v)){
				t.e[++ t.m] = {u, v, w};
				s.uni(u, v);
				ret += w;
			}
		}
		return ret ;
	}
}o;

Tree dp[15];
ll ans[15];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(), m = read(), K = read();
	for(int i=1; i<=m; ++ i){
		int u = read(), v = read(); ll w = read();
		o.e[i] = {u, v, w};
	}
	for(int i=1; i<=K; ++ i){
		c[i] = read();
		for(int j=1; j<=n; ++ j){
			a[i][j] = read();
		}
	}
	
	//pre
	o.kruskal(dp[0]);
	for(int i=1; i<=K; ++ i){
		int now = i + n;   //当前村庄的总体编号
		Tree nowt = dp[i-1];  
		Kruskal_Rebuild_Tree nowk;  //当前重构树
		
		//先默认连1
		++ nowt.n;
		nowt.e[++ nowt.m] = {now, 1, a[i][1]};
		ll mst = nowt.kruskal(nowk);   //连1时的最小生成树
		nowk.dfs(nowk.rt, 0);
		ll mn = mst, mni = 0;   //再看一下其它的连法能不能替换连1的
		for(int j=2; j<=n; ++ j){
			ll ori = nowk.v[nowk.lca(now, j)];   //原边
			ll nw = a[now][j];      //新边
			if(nw > ori)  continue ;
			ll nowmst = mst - ori + nw;
			if(nowmst < mn)  mn = nowmst, mni = j;
		}

		if(mn < ans[i-1]){
			ans[i] = mn;
			dp[i] = dp[i-1];
			++ dp[i].n;
			dp[i].e[++ dp[i].m] = {now, (int)mni, a[i][mni]};
		}else{
			ans[i] = ans[i-1];
			dp[i] = dp[i-1];
		}
	}

	print(ans[K], '\0');
	return 0;
}

