#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e5;
int n,m,k;
struct node{
	int v,w,c;
};
vector<node> e[N];
int dis[N];
bool vis[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	q.push({0,s});
	dis[s] = 0;
	while(!q.empty()){
		auto t = q.top();
		q.pop();
		int u = t.second();
		if(vis[u] == 1) continue;
		vis[u] = 1;
		for(auto ed : e[u]){
			int v = ed.v;
			int w = ed.w;
			int c = ed.c; 
			if(dis[v] > dis[u] + w + c) 
			{
				dis[v] = dis[u] + w + c;
				ed.c = 0;
			}
			q.push({dis[v],v});
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w,0});
		e[v].push_back({u,w,0});
	}
	for(int i = 1; i <= k; i++){
		int c;
		cin >> c;
		for(int j = 1; j <= n; j++){
			int a;
			cin >> a;
			e[i + n].push_back({j,a,c});
			e[j].push_back({i + n,a,c});
		}
	}
	dijkstra(1);
	int maxn = 0;
	for(int i = 1; i <= n; i++){
		if(dis[i] == 0x3f) continue;
		maxn = max(dis[i],maxn);
	}
	cout << maxn;
	return 0;
}
