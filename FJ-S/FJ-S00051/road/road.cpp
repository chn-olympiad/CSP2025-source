#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=5e6+5;
const int inf=2000000005;
int n,m,k,cnt;
int dis[maxn],vis[maxn],head[maxn],c[maxn];
int a[maxn][11];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
struct EDGE{
	int to,nxt,w;
}e[maxm];
void addedge(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void spfa(int s){
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[s]=0;
	vis[s]=1;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push({dis[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	} 
	spfa(1);
	cout<<dis[n];
	return 0;
}
