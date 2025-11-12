#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
struct node{
	int v,w;
};
vector<node>adj[MAXN];
int n,m,k;
int c[15];
int a[15][MAXN];
bool open[15];
queue<int>q;
ll dis[MAXN];
void SPFA(int u){
	memset(dis,1e10,sizeof(dis));
	q.push(u);
	dis[u]=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(auto e:adj[x]){
			int v=e.v,w=e.w;
			if(dis[v]>w){
				dis[v]=w;
				q.push(v);
			}
		}
	}
	return;
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int j=1;j<=m;j++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int l=1;l<=n;l++){
			cin>>a[j][l];
		}
	}
	SPFA(1);
	ll ans=0;
	for(int j=1;j<=n;j++){
		ans+=dis[j];
	}
	cout<<ans;
	return 0;
}
