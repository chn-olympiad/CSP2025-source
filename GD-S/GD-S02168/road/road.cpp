#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
// 对于测试点1-4: 直接最小生成树即可
// core problem:如何建图？
// no idea，先写下一题
// 目标:混四个点(16分)
const int N=1e6+9;
struct Edge {
	int weight,to,from;
};
int fa[N];
//vector<Edge>g[N];
Edge e[N];
bool cmp(Edge a,Edge b) {
	return a.weight<b.weight;
}
int get_fa(int index) {
	int father = index;
	if(fa[index]!=0 && fa[index] != index) {
		father = get_fa(fa[index]);
	}
	fa[index] = father;
	return father;
}
//void debug() {
//	for(int i=1; i<=m; i++) {
//		printf("edge:%lld,from:%lld,to:%lld,weight:%lld\n",i,e[i].from,e[i].to,e[i].weight);
//	}
//}
signed main() {
	// 记得取消注释!!!!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[i] = {w,u,v};
	}
	sort(e+1,e+m+1,cmp);
//	debug();
	int ans=0;
	for(int i=1; i<=n; i++) {
		Edge edge = e[i];
		if(get_fa(edge.from) != get_fa(edge.to)) {
			ans+=edge.weight;
			fa[edge.from] = edge.to;
		}
	}
	cout<<ans;
	return 0;
}
