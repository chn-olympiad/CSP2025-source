#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5,N=2e4+5;
priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > p;
vector<pair<int,int> > vec[M];
int n,m,k,dis[M],vis[N],w,ans;
void dij(int u,int fa){
	for(int i=0;i<vec[u].size();i++){
		int v=vec[u][i].first,w=vec[u][i].second;
		if(v==fa) continue;
		if(dis[v]>dis[u]+w){
			ans+=w;
			dis[v]=dis[u]+w;
			dij(v,u);
		}
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}if(k==0){
		memset(dis,M,sizeof(M));
		dis[1]=0;
		dij(1,0);
		printf("%lld",ans);
	}
	return 0;
} 
