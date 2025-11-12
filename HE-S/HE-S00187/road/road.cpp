#include<bits/stdc++.h>
#define ll long long
using namespace std;
//MST
const int N=1e4+5,M=1e6+5,K=11;
int n,m,k,w1[N];
ll ans,h[N+K];
bool vis[N+K];
struct edge{
	int v,w;
};
vector<edge> e[N];
priority_queue<pair<ll,int> >q;
void Prim(){
	memset(h,0x3f,sizeof h);
	int cnt=0;
	h[1]=0;
	q.push({0,1});
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		ans+=h[u];
//		printf("u=%d ans=%d\n",u,ans);
		if(u<=n) cnt++;
		if(cnt==n) break;
		for(auto ed:e[u]){
			int v=ed.v,w=ed.w; 
			if(h[v]>h[u]+w){
				h[v]=h[u]+w;
				
				q.push({-h[v],v});
//				printf("pushed %d with %d in queue\n",v,h[v]);
			}
		}
	}
	
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int w;cin>>w;
		for(int j=1;j<=n;j++){
			
			cin>>w1[j];
			
			
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(k==j) continue;
				e[j].push_back({k,w1[j]+w1[k]});
				e[k].push_back({j,w1[j]+w1[k]});
			}
		}
			
	}
	Prim();
	cout<<ans;
	return 0;
} 
