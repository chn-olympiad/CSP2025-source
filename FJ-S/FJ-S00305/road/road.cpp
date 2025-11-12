#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
bool flag = 0;
const int MAXN = 1e6 + 5;

struct edge{
	int to,val;
	bool operator < (const edge &s) const{
		return val < s.val;
	}
};

int a[15][10005];
int c[15];
vector<edge> G[MAXN];
int dis[MAXN];
bool vis[MAXN];

inline void dijkstra(){
	priority_queue<edge> q;
	q.push({1,0});
	for(int i = 1;i <= m;i++){
		dis[i] = 1e9;
	}
	dis[1] = 0;
	while(!q.empty()){
		edge tmp = q.top();
		q.pop();
		int u = tmp.to;
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(int i = 0;i < G[u].size();i++){
			int v = G[u][i].to;
			if(vis[v] == 0){
				dis[v] = min(dis[v],tmp.val + G[u][i].val);
				q.push({v,dis[v]});
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int j = 1;j <= k;j++){
		cin>>c[j];
		/*if(c[j] != 0){
			flag = 1;
		}*/
		for(int i = 1;i <= n;i++){
			cin>>a[j][i];
			/*if(a[j][i] != 0){
				flag = 1;
			}*/
			G[j].push_back({i,a[j][i]});
			G[i].push_back({j,a[j][i]});
		}
	}
	/*if(flag == 0){
		for(int j = 1;j <= k;j++){
			for(int i = 1;i <= n;i++){
				G[j].push_back({i,0});
				G[i].push_back({j,0});
			}
		}
	}*/
	dijkstra();
	cout<<dis[n];
	return 0;
}
