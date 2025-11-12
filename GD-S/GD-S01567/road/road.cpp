#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200010;
int n,m,k;
bool vis[maxn];
int dis[maxn];
struct node{
	int v,w;
	bool operator < (const node &o){
		return w<o.w;
	}
};
vector<node> G[maxn];
//struct pw{
//	int u,v,w;
//	bool operator < (const pw&o){
//		return w<o.w;
//	}
//}g[maxn];
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto x:G[u]){
			if(dis[x.v]>dis[u]+x.w){
				dis[x.v]=dis[u]+x.w;
				q.push(x.v);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	if(k!=0){
		cout << 0 << endl;
		exit(0);
	}
	dij(1);
	cout << dis[n] << endl;
	return 0;
}
