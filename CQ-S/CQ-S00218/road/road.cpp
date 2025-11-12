#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct node{
	int id,dis;
	friend bool operator<(node x,node y){
		return x.dis>y.dis;
	}
};
int n,m,k;
vector<int>g[maxn],w[maxn];
int dist[maxn];
bool done[maxn];
priority_queue<node>q;
void dij(int st){
	memset(dist,0x3f,sizeof(dist));
	memset(done,false,sizeof(done));
	q.push({st,0});dist[st]=0;
	while(!q.empty()){
		int i=q.top().id;q.pop();
		if(done[i])continue;
		done[i]=true;
		for(int k=0;k<g[i].size();k++){
			int j=g[i][k],c=w[i][k];
			if(dist[i]+c<dist[j]){
				dist[j]=dist[i]+c;
				q.push({j,dist[j]});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,c;cin>>u>>v>>c;
		g[u].push_back(v);
		g[v].push_back(u);
		w[u].push_back(c);
		w[v].push_back(c);
	}/*for(int i=1;i<=k;i++){
		int c;cin>>c;
		for(int j=1;j<=n;j++){
			int a;cin>>a;
			g[c].push_back(j);
			g[j].push_back(c);
			w[c].push_back(a);
			w[j].push_back(a);
		}
	}*/int ans=0;
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++){
			ans=max(ans,dist[j]);
		}
	}cout<<ans;
	/*dij(1);
	for(int i=1;i<=n;i++){
		//cout<<dist[i]<<' ';
		ans=max(ans,dist[i]);
	}cout<<ans;*/
	return 0;
}

