#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int nxt,to,w;
} e[4000010];
int n,m,k;
int head[1000010],tot=0,wes[11][10010],c[11];
void add(int u,int v,int w){
	e[++tot]={head[u],v,w};
	head[u]=tot;
}
int ans=0x3f3f3f3f,dis[10010];
bool vis[10020];
map<int,int> mp;
bool cmp(node x,node y){
	return x.w<y.w;
}
void bfs(){
	queue<int> q;
	memset(dis,0x3f3f3f3f,sizeof dis);
	q.push(1);
	dis[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				mp[e[i].w]=1;
				q.push(v);
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n+k;i++) maxn=max(maxn,dis[i]);
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=tot;i++)
		if(!mp[e[i].w]){
			cout<<maxn+e[i].w<<'\n';
			return;
		}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>wes[i][j];
			add(i+n,j,wes[i][j]);
			add(j,i+n,wes[i][j]);
		}
	}
	bfs();
	return 0;
}
