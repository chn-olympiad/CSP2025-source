#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e6+10,maxn=1e4+10,INF=1e9;
int n,m,k;
int c[15],a[15][N],dp[maxn],d[maxn];
int vis[maxn];
bool ok[15];
int ans=0;
vector<pair<int,int> > g[N];
struct node{
	int v,w;
};
void bfs(int x){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,x});
	while(q.size()){
		auto e=q.top();q.pop();
		int u=e.second,w=e.first;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:g[u]){
			int v=i.first,wi=i.second;
			if(d[u]+wi<d[v]){
				d[v]=d[u]+wi;
				ans+=wi;
				q.push({d[v],v});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,wi;
		cin>>u>>v>>wi;
		g[u].push_back({v,wi});
		g[v].push_back({u,wi});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	fill(d+1,d+n+1,INF);
	d[1]=0;
	bfs(1);
	cout<<ans;
	return 0;
}
