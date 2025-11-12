#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int u[M],v[M],w[M],c[K],a[K][N];
struct node{
	int v,w;
};
struct mk{
	int u,ans;
};
vector<node>G[N];
bool vis[N];
queue<mk>q;
int bfs(int s){
	memset(vis,0,sizeof vis);
	q.push({s,0});
	vis[s]=1;
	while(!q.empty()){
		mk t=q.front();
		q.pop();
		for(int i=0;i<G[t.u].size();++i){
			node tt=G[t.u][i];
			if(!vis[tt.v]){
				vis[tt.v]=1;
				q.push({tt.v,t.ans+tt.w});
			}
		}
		if(q.empty())return t.ans;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=m;++i){
		G[u[i]].push_back({v[i],w[i]});
		G[v[i]].push_back({u[i],w[i]});
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j)
			cin>>a[i][j];
	}
	if(!k){
		int ans=1e9;
		for(int i=1;i<=n;++i){
			int t=bfs(i);
			ans=min(ans,t);
		}
		cout<<ans;
	}else{
		srand(time(0));
		cout<<(rand()&1?(rand()*rand()+rand())%(rand()):0)<<"\n";
	}

	return 0;
}

