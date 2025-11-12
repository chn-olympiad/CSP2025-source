#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}
	return f*x;
}
int n,m,k,ans;
int c[11],a[11][10001];
int head[10001];
int nxt[1000001],to[1000001],cost[1000001],cnt;
int vis[10001];
struct Node{
	int d,r;
}dist[10001];
void add(int u,int v,int w){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	cost[cnt]=w;
	head[u]=cnt;
	nxt[++cnt]=head[v];
	to[cnt]=u;
	cost[cnt]=w;
	head[v]=cnt;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
//		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		dist[i].d=INT_MAX;
		dist[i].r=0;
	}
	vis[1]=1,dist[1].d=-1;
	for(int i=head[1];i>0;i=nxt[i]){
		dist[to[i]].d=cost[i];
		dist[to[i]].r=0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(dist[i].d>a[j][1]+c[j]+a[j][i]){
				dist[i].d=a[j][1]+c[j]+a[j][i];
				dist[i].r=j;
			}
		}
//		cout<<dist[i].d<<" "<<dist[i].r<<endl;
	}
	for(int i=2;i<=n;i++){
		int mindist=INT_MAX,minpos;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dist[j].d<mindist){
				mindist=dist[j].d;
				minpos=j;
			}
		}
		ans+=dist[minpos].d;
//		cout<<ans<<endl;
		vis[minpos]=1,dist[minpos].d=-1;
		for(int j=head[minpos];j>0;j=nxt[j]){
			if(cost[j]<dist[to[j]].d){
				dist[to[j]].d=cost[j];
				dist[to[j]].r=0;
			}
		}
		if(dist[minpos].r!=0){
			for(int j=1;j<=n;j++){
				if(vis[j]==0&&a[dist[minpos].r][j]<dist[j].d){
					dist[j].d=a[dist[minpos].r][j];
					dist[j].r=0;
				}
			}
		}
//		for(int j=1;j<=n;j++)
//			cout<<dist[j].d<<" "<<dist[j].r<<endl;
	}
	cout<<ans;
	return 0;
}
/*     */
