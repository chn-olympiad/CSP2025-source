#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,u,v,w,len[10010],ans,c[20],a[20][10010],vis[10010],cnt;
ll dis[10010],d[20];
struct edge{
	int v,w,next;
}e[2000100];
struct PII{
	int d;
	ll ss;
};
queue<PII> q;
void add(int x,int y,int z) {
	e[++ans].next=len[x];
	e[ans].v=y;
	e[ans].w=z;
	len[x]=ans;
}
void dijkstra(int t) {
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[t]=0;
	q.push({t,0});
	while(!q.empty()) {
		int u=q.front().d,ss=q.front().ss;
		q.pop();
		for(int i=len[u];i;i=e[i].next) {
			int v=e[i].v;
			ll w=e[i].w;
			if(dis[v]>ss+w) {
				dis[v]=ss+w;
				q.push({v,dis[v]});
				vis[v]=w;
			}
		}
	}
}
int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dijkstra(1);
	++cnt;
	for(int i=1;i<=n;i++) {
		d[cnt]+=vis[i];
	}
	for(int i=1;i<=k;i++) {
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			add(n+i,j,a[i][j]);
			add(j,n+i,a[i][j]);
		}
		d[++cnt]=c[i];
		dijkstra(1);
		for(int j=1;j<=n+i;j++) {
			d[cnt]+=vis[j];
		}
 	}
 	sort(d+1,d+cnt+1);
 	printf("%lld",d[1]);
	
	return 0;
} 
