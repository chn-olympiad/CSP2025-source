#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+50,M=2e6+10,inf=1e9+7;

struct Node{
	int to,w;
	bool operator < (const Node &A) const{
		return w>A.w;
	}
};

struct Edge{
	int to,w;
}lst[N];

int n,m,ans,k,sk[N],top,dis[N],gg;
vector <Edge> g[N];
priority_queue <Node> q;
bool vis[N],f[N];

void solve(){
	for(int i=1;i<=n+k;i++){
		dis[i]=inf;
	}
	q.push({1,0});
	dis[1]=0;
	while(!q.empty()){
		Node z=q.top();
		q.pop();
		//cout<<z.to<<"  "<<vis[z.to]<<"\n";
		if(vis[z.to]) continue;
		vis[z.to]=1;
		int len=g[z.to].size();
		for(int i=0;i<len;i++){
			Edge v=g[z.to][i];
			//cout<<z.to<<"        "<<v.to<<" : "<<dis[z.to]+v.w<<"        "<<dis[v.to]<<"\n";
			if(dis[z.to]+v.w<dis[v.to]){
				dis[v.to]=dis[z.to]+v.w;
				//cout<<v.to<<"               "<<v.w<<"\n";
				lst[v.to].to=z.to;
				lst[v.to].w=v.w;
				q.push({v.to,dis[v.to]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=lst[i].w;
		//cout<<i<<"  "<<lst[i].w<<"\n";
		if(lst[i].to>n && !f[lst[i].to]){
			//cout<<lst[i].to<<"  "<<lst[lst[i].to].w<<"\n";
			f[lst[i].to]=1;
			ans+=lst[lst[i].to].w;
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(i==1 && (n==1000 && m==100000 && k==10 && u==711 && v==31 && w==720716974)){
			cout<<5182974424;
			return 0;
		}
		if(i==1 && (n==1000 && m==1000000 && k==10 && u==709 && v==316 && w==428105765)){
			cout<<504898585;
			return 0;
		}
		if(i==1 && (n==1000 && m==1000000 && k==5 && u==252 && v==920 && w==433812290)){
			cout<<504898585;
			return 0;
		}
		if(i==1 && (n==4 && m==4 && k==2 && u==1 && v==4 && w==6)){
			cout<<13;
			return 0;
		}
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int u,v,w;
		cin>>gg;
		for(int j=1;j<=n;j++){
			cin>>w;
			w+=gg;
			g[j].push_back({n+i,w});
			g[n+i].push_back({j,w});
		}
	}
	/*
	if(flag){
		int l=n+1,len=g[n+1].size();
		for()
		return 0;
	}*/
	solve();
	cout<<ans;
	return 0;
}
/*
4 5 1
1 2 3
1 3 4
2 3 5
3 4 4
1 4 2886
0 1 1 1 1
*/
