#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int to,w,next;
}e[100001];
int head[100001],cnt=0,dis[10001],vis[100001],n,m,k;
void dij(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof dis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	dis[x]=0;
	q.push({x,0});
	while(!q.empty()){
		auto nw=q.top();
		q.pop();
		int u=nw.first,dist=nw.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i!=-1;i=e[u].next){
			int j=e[u].to;
			if(dis[j]>e[i].w+dist) {
				dis[j]=e[i].w+dist;
				q.push({j,dis[j]});
			}
		}
	}
}
void add(int x,int y,int w){
	e[cnt].to=y;
	e[cnt].w=w;
	e[cnt].next=head[x];
	head[x]=cnt;    
	cnt++;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof head);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
	}
	dij(1);
	for(int i=1;i<=n;i++) ans+=dis[i];
	cout<<ans;
	return 0;
}
