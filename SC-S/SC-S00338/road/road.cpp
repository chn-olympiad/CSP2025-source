#include<bits/stdc++.h>

using namespace std;

#define x1 maimaim41m41
#define x2 chunithmchu2thm
#define y1 ongeki0n93k1
#define y2 phigrosph9r
#define il inline
//bool st;
// 敢于硬算 勇于巧算 乐于不算 精于预算

// 再检查检查有没有溢出吧
// 还要算一算空间
typedef long long ll;

int n, m, k;

const int N = 1e4+50;
const int M = 1e6+6;
const int STAT_MAX = 1024;

struct Edge{
	int u, v, w;
}oriEdge[M];

struct DSU{
	int fa[N];
	inline void clear(int mai){
		for(int i=1;i<=mai;i++){
			fa[i] = i;
		}
	}
	inline int getfa(int x){
		return (fa[x] == x)? x: fa[x] = getfa(fa[x]);
	}
	inline void merge(int x, int y){
		x = getfa(x), y = getfa(y);
		fa[x] = y;
	}
}dsu;

const int NEWPT = 12;
int newEdges[NEWPT][N];
int buildCost[NEWPT];
Edge tmpSortedge[N<<1];

int curlayer = 0;
ll ans = 0;
struct Layer{
	Edge edgeSet[N];
	int binaIdx; // 该层的二进制对应编号
}layer[NEWPT];



inline Edge makeEdge(int u, int v, int w){
	Edge edgeMade;
	edgeMade.u = u, edgeMade.v = v, edgeMade.w = w;
	return edgeMade;
}

inline void getMST(){
	ll curans = 0;
	int lastEdgecnt = n+curlayer-1;
	for(int i=1;i<=lastEdgecnt;i++){
		tmpSortedge[i] = layer[curlayer-1].edgeSet[i];
	}
	int curBinaidx = layer[curlayer].binaIdx;
	int diffBinaidx = layer[curlayer].binaIdx ^ layer[curlayer-1].binaIdx;
	int diffidx = __lg(diffBinaidx) + 1;
	for(int i=1;i<=n;i++){
		tmpSortedge[lastEdgecnt+i] = makeEdge(diffidx+n, i, newEdges[diffidx][i]);
	}
	for(int i=1;i<=k;i++){
		if(((1<<(i-1))&curBinaidx)){
			curans += buildCost[i];
		}
	}
//	cout<<diffidx<<' '<<curans<<' ';
	int curm = lastEdgecnt + n;
	sort(tmpSortedge+1, tmpSortedge+1+curm, [&](const Edge &x,const Edge &y){return x.w < y.w;});
	dsu.clear(n+k);
	int curinsertidx = 0;
	for(int i=1;i<=curm;i++){
		Edge curedge = tmpSortedge[i];
		if(dsu.getfa(curedge.u) != dsu.getfa(curedge.v)){
			layer[curlayer].edgeSet[++curinsertidx] = curedge;
			curans += curedge.w;
			dsu.merge(curedge.u, curedge.v);
		}
	}
	ans = min(ans, curans);
	
}
//bool ed;
void maisolve(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>oriEdge[i].u>>oriEdge[i].v>>oriEdge[i].w;
	}
//	cerr<<"!!!\n";
	sort(oriEdge+1, oriEdge+1+m, [&](const Edge &x,const Edge &y){return x.w < y.w;});
	dsu.clear(n);
	int curinsertidx = 0;
	for(int i=1;i<=m;i++){
		Edge curedge = oriEdge[i];
		if(dsu.getfa(curedge.u) != dsu.getfa(curedge.v)){
//			cout<<dsu.getfa(curedge.u)<<' '<<dsu.getfa(curedge.v)<<'\n';
//			cout<<curedge.u<<' '<<curedge.v<<'\n';
			layer[0].edgeSet[++curinsertidx] = curedge;
			ans += curedge.w;
			dsu.merge(curedge.u, curedge.v);
		}
	}
//	cout<<ans<<'\n';
	for(int i=1;i<=k;i++){
		cin>>buildCost[i];
		for(int j=1;j<=n;j++){
			cin>>newEdges[i][j];
		}
	}
//	cerr<<"Input Complete\n";
	for(int curBinaidx=1;curBinaidx<(1<<k);curBinaidx++){
		while(__builtin_popcount(curBinaidx ^ layer[curlayer].binaIdx) != 1){
			curlayer --;
		}
		curlayer ++;
		layer[curlayer].binaIdx = curBinaidx;
		getMST();
//		cout<<curBinaidx<<": "<<ans<<'\n';
	}
	cout<<ans<<'\n';
//	cerr<<(&ed-&st)/1024.0/1024.0<<"MB\n";
}
void duoceclear(){
	
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ,cout.tie(0);
	int t = 1;
//	cin>>t;
	while(t--){
		maisolve();
		duoceclear();
	}
	return 0;
	
}