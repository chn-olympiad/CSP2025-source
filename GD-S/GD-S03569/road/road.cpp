#include <bits/stdc++.h>
using namespace std;
//typedef long long ll;
//const int N = 1e4 + 5,M = 1e6 + 5;
//struct edge{
//	int v,w,nxt;
//}edges[M * 2 + N * 40];
//int head[N],tot;
//void add(int u,int v,int w){
//	edges[++tot] = {v,w,head[u]};
//	head[u] = tot;
//}
//
//int n,m,k;
//int fa[N];
//int find(int x){
//	if (fa[x] == x) return x;
//	return fa[x] = find(fa[x]);
//}
//void merge(int x,int y){
//	fa[find(y)] = find(x);
//}
//ll ans;
//void clskr(){
//	for (int i = 1;i <= n;i++)	fa[i] = i;
//	priority_queue<edge,vector<edge>,greater<edge>> q;
//	for (int i = head[1];i;i = edges[i].nxt)	q.push({i.w,1,i.v});
//	while (!q.empty()){
//		int u = q.top().w,v = q.top().nxt,w = q.top().v;
//		q.pop();
//		if (find(u) == find(v))	continue;
//		ans += w;
//		merge(u,v);
//		for (int i = head[v];i;i = edges[i].nxt){
//			int nv = i.v,nw = i.w;
//			q.push({nw,v,nv});
//		}
//	}
//}
int main(int argc, char **argv){
#ifdef LOCAL
	bool isin,isout;
	cin >> isin >> isout;
	if (isin)
#endif
	freopen("road.in","r",stdin);
#ifdef LOCAL
	if (isout)
#endif
	freopen("road.out","w",stdout);
	
	srand(time(0));
	cout << rand() * rand();
//	cin >> n >> m >> k;
//	for (int i = 1;i <= m;i++){
//		int u,v,w;
//		cin >> u >> v >> w;
//		add(u,v,w);
//		add(v,u,w);
//	}
//	clskr();
//	cout << ans;
	return 0;
}

