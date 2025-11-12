#include <bits/stdc++.h>
using namespace std;
const int M=2e6+5,N=1e4+25;
const int inf=INT_MAX;
struct node{
	int dis,to;
	friend bool operator<(node a,node b){
		return a.dis<b.dis;
	}
};
int n,m,k;
int nxt[M],to[M],val[M],h[M],dis[M],c[15],cnt;
int a[15][N]; bool vis[N],vis1[N+15];
priority_queue<node> q;
int prim(int s){
	for(int i=1;i<=n;i++)
		dis[i]=inf;
	int ans=0,tot=0; dis[s]=0;
	q.push((node){0,s});
	while(!q.empty()){
		int u=q.top().to; q.pop();
		if(vis[u]) continue;
		ans+=dis[u]; vis[u]=1; tot++;
		for(int i=h[u];i;i=nxt[i])
			if(dis[to[i]]>val[i] && !vis[to[i]]){
				dis[to[i]]=val[i];
				q.push((node){dis[to[i]],to[i]});
			}
//		if(q.empty() && tot<n){
//			q.push()
//		}0
	}
	return ans;
}
void add(int u,int v,int w){
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for(int i=1,w;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			add(i+n,j,w);
		}
	}
	printf("%d",prim(1));
	return 0;
}
