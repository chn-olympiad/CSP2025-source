#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>

using namespace std;

const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int n,m,k;
int a[37][maxn];
int g[maxn];
int visk[maxn],vis[maxn],dis[maxn];
vvpii p(maxn+10);

void dijkstra(int x){
	priority_queue<pii,vpii,greater<pii>> q;
	q.push({x,0});
	for(int i=1;i<=n;++i){
		dis[i]=inf;
		vis[i]=0;
	}
	
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		
		int u=t.first,len=t.second;
		
		if(vis[u]) continue;
		vis[u]=1;
		
		for(auto i:p[u]){
			int v=i.first,w=i.second;
			if(len+w<dis[v]){
				dis[v]=len+w;
			}
			int d=0;
			for(int i=1;i<=k;++i){
				if(g[i]+a[i][u]+a[i][v]<dis[v]){
					dis[v]=g[i]+a[i][u]+a[i][v];
					d=i;
				}
			}
			if(d) visk[d]=1;
			q.push({v,dis[v]});
		}
	}
	
	return;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int u,v,w,i=1;i<=m;++i){
		cin>>u>>v>>w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	for(int i=1;i<=k;++i){
		cin>>g[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	
	dijkstra(1);
	
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=dis[i];
		if(visk[i]) ans+=g[i];
	}
	
	cout<<ans<<'\n';
	return 0;
} 
