#include<bits/stdc++.h>
using namespace std;
#define LL long long 
int n,m,k,u,v,w;
LL ans;
const int ri=1e4+5;
bool vis[ri];
struct edge{
	int v,w;
};
struct node{
	int u; LL dis;
	bool operator<(const node &x)const{
		return x.dis>dis; 
	}
};
vector<edge> e[ri]; 
int a[15][ri],fo;
LL dis[ri];
void dijkstra(int u){
	priority_queue<node> q;
	for(int i=1;i<=n;i++)
	    dis[i]=1e18,vis[i]=0;
	q.push({u,0});
	dis[u]=0;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		int u=t.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v,w=e[u][i].w;
			for(int j=1;j<=k;j++){
				w=min(w,a[j][u]+a[j][v]); 
		    }
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			
		}}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=k;i++){
		if(a[i][0]!=0){fo=1; break;}
	}
	if(!fo){
		dijkstra(1);
		for(int i=1;i<=n;i++){
			ans+=dis[i];
	 }
		printf("%lld\n",ans);
	}
	return 0;
} 
