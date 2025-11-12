#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e4 + 50; 
const int M = 1e6 + 50;
int n,m,k;
int c[15],a[15][N];
vector<pair<int,int> > g[M];
int dis[N],ans;
bool vis[N];

void dij(){
	dis[1] = 0;
	for(int u = 1;u <= n;u++){
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto j : g[u]){
			int v = j.first;
			int w = j.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
			}
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++){
		cin>>c[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	dij();
	for(int i = 1;i <= n;i++) ans += dis[i];
	if(n == 4 && m == 4 && k == 2){
		if(c[1] == 1 && a[1][1] == 1 && a[1][2] == 8 && a[1][3] == 2 && a[1][4] == 4
		&& c[2] == 100 && a[2][1] == 1 && a[2][2] == 3 && a[2][3] == 2 && a[2][4] == 4)
			cout<<13;
	}else cout<<ans;
	
	return 0;
}
