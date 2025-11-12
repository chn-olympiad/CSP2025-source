#include<bits/stdc++.h>
using namespace std;
const int Max=1e4+10;
const int INF=1e18+10;
struct Edge{
	int v,w;
};
struct Node{
	int id,w;
	bool operator<(const Node Z)const {
		return Z.w<w;
	}
};
int n,m,k,ans;
int dis[Max][Max];
bool vis[Max];
vector<Edge >a[Max];
void dij(){
	priority_queue<Node >q;
	q.push(Node{1,0});
	vis[1]=true;
	for(int i=1;i<=Max;i++){
		for(int j=1;j<=Max;j++){
			dis[i][j]=INF;
		}
	}
	while(!q.empty()){
		int u=q.top().id;
		ans+=q.top().w;
		q.pop();
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].v;
			int w=a[u][i].w;
			if(dis[u][v]>a[u][v].w+w){
				if(vis[v]==false){
					dis[u][v]=a[u][v].w+w;
					q.push(Node{v,w});
					vis[v]=true;
				}
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1,x;j<=n;j++){
			cin>>x;
			a[0].push_back({j,x+c});
			a[j].push_back({0,x+c});
		}
	}
	dij();
	return 0;
}
