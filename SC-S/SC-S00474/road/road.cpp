#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+14,inf=1e9+7;
struct Edge{ll v,w;};
vector<Edge> g[N];
int c[11],a[11][N];
int n,m,k;
struct Node{
	ll d,id;
	friend bool operator < (const Node& a,const Node& b){
		return a.d>b.d;
	}
};
bool vis[N]; ll dis[N];
ll prim(int tot){
	for(int i=1;i<=n+k;i++) vis[i]=0,dis[i]=inf; dis[1]=0;
	int cnt=0; ll ans=0;
	while(cnt<tot){
		int u,midis=inf;
		for(int i=1;i<=n+k;i++)
			if(dis[i]<midis&&!vis[i]) u=i,midis=dis[i];
		ans+=midis,vis[u]=1,++cnt;
		for(Edge e:g[u]) if(!vis[e.v]){
			dis[e.v]=min(dis[e.v],e.w);
		}
	}
//	cout<<ans<<" ";
	return ans;
}
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll ans=1e18; cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++) cin>>u>>v>>w,
		g[u].push_back({v,w}),g[v].push_back({u,w});
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j],g[n+i+1].push_back({j,a[i][j]});
	}
	for(int i=0;i<(1<<k);i++){// 调试
		ll res=0; int cnt=n;
		for(int j=0;j<k;j++) if((1<<j)&i){
			res+=c[j],++cnt;
			for(int l=1;l<=n;l++)
				g[l].push_back({n+j+1,a[j][l]});
		}
//		for(int i=1;i<=5;i++){
//			for(Edge e:g[i]) cout<<e.v<<" "<<e.w<<"\n";
//			cout<<"\n";
//		}
		res+=prim(cnt);
		for(int j=0;j<k;j++) if((1<<j)&i)
			for(int l=1;l<=n;l++) g[l].pop_back();
		ans=min(ans,res);
		//cout<<res<<" ";
	}
	cout<<ans; return 0;
}