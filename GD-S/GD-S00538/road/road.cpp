#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+50;
struct edge{
	int v,w;
};
struct node{
	int u,dis;
	bool operator < (const node &a) const{
		return dis>a.dis;
	}
};
int n,m,k,ans;
int dis[N],pre[N],used[N],c[N],kk[20][20];
bool vis[N];
vector<edge> g[N];
void prim(){
	for(int i=0;i<=n+k;i++){
		dis[i]=1e18;
	}
	priority_queue<node> q;
	q.push({1,0});
	dis[1]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		vis[u]=true;
		//cout<<u<<" "<<dis[u]<<'\n';
		for(auto p:g[u]){
			int v=p.v,w=p.w;
			if(!vis[v]){
				if(dis[v]>w){
					dis[v]=w;
					if(u>n){
						dis[v]+=dis[u]-c[u];
						used[pre[v]]--;
						used[u]++;
						pre[v]=u;
					}
					q.push({v,dis[v]});
					//cout<<u<<"->"<<v<<'\n'; 
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	for(int i=1;i<=k;i++){
		if(used[i+n]>0){
			ans-=(used[i+n]-1)*c[i+n];
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int cc;
		cin >> cc;
		c[i+n]=cc; 
		for(int j=1;j<=n;j++){
			int x;
			cin >> x;
			g[j].push_back({i+n,x+cc});
			g[i+n].push_back({j,x+cc});
		}
	}
	prim();
	cout<<ans;
	return 0;
}
/*
4 5
1 4 100
1 3 1
1 2 100
2 3 1
3 4 1
*/
