#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+1e3;
int n,m,k,ans,d[N];
struct edge{int v,w;};vector<edge>e[N];
inline void dij(int st){
	priority_queue<pair<int,int> >q;
	q.push({0,st});memset(d,0x3f3f3f3f,sizeof d);d[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w;
			if(d[v]>d[u]+w)d[v]=d[u]+w,q.push({-d[v],v});
		}
	}
	for(int i=1;i<=n;++i)ans+=d[i];
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m&&cin>>u>>v>>w;++i){
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	for(int i=1;i<=k;++i){
		int x;cin>>x;
		for(int j=1,w;j<=n&&cin>>w;++j)e[n+1].push_back((edge){j,x+w});
	}
	dij(1);
	cout<<ans;
	return 0;
} 
