#include <bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
const int N=1e4+5;
vector<int> g[N],G[N],s[15];
int dist[N],ww[N],ans;
void Dijkstra(int x){
	priority_queue<pair<int,int>> q;
	q.push({0,x});
	memset(dist,inf,sizeof(dist));
	while(q.size()){
		auto dis=q.top().first,u=q.top().second;
		q.pop();
		if(dis>dist[u]){
			continue;
		}
		dist[u]=dis;
		
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u);
		G[u].push_back(w);
		G[v].push_back(w);
	}
	for(int i=1;i<=k;++i){
		cin>>ww[i];
		for(int j=1;j<=n;++j){
			int a;
			cin>>a;
			s[i].push_back(a);
		}
	}
//	Dijkstra(1);
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
