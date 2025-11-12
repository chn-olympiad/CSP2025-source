#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c;
long long dis[200005],ans,res,len[200005];
struct edge{
	int v,w;
};
vector<edge>e[200005];
int cnt;
bool vis[200005];
int fa[200005];
bool viss[200005];
priority_queue<pair<int,int> >q;
unordered_map<int,int>mp[200005];
void dji(int u){
	q.push({0,u});
	dis[u]=0ll;
	fa[u]=0;
	while(!q.empty()){
		int ab=q.top().second;
		q.pop();
		vis[ab]=1;
		for(auto ed:e[ab]){
			int vv=ed.v,ww=ed.w;
			if(vis[vv]) continue;
			if(dis[ab]+ww<dis[vv]){
				fa[vv]=ab;
				dis[vv]=dis[ab]+ww;
				q.push({-dis[vv],vv});
				vis[vv]=1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			e[j].push_back({n*i+i,c});
		}
		for(int j=1;j<=n;j++){
			cin>>w;
			e[n*i+i].push_back({j+i*n+i,w});
			e[j+i*n+i].push_back({n*i+i,w});
		}
	}
	memset(dis,0x3f3f,sizeof(dis));
	dji(1);
	dis[0]=0;
	for(int i=1;i<=n;i++){
		res=dis[i]-dis[fa[i]];
		for(int j=1;j<=k;j++){
			res=min(res,dis[i+j*n+j]);
		}
		ans+=res;
	}
	cout<<ans<<"\n";
	return 0;
}