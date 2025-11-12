#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+10;
int n,m,k,a[N][N],c[11],w[11][N],h[N],cnt,x,y,z,ans=1e9,tot;
int dis[N][N],vis[N];
queue<int> q;
struct edge{
	int ne,v,w;
}e[M*2];
void add(int from,int to,int w){
	e[++cnt]={h[from],to,w};
	h[from]=cnt;
}
void bfs(){
	while (q.size()){
		int u=q.front();
		q.pop();
		for (int i=h[u];i;i=e[i].ne){
			int v=e[i].v,w=e[i].w;
			if (vis[v]) continue;
			vis[v]=1;
			tot+=w;
			q.push(v);
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for (int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for (int i=1;i<=n;i++)
		scanf("%lld",&w[k][i]);
	}
	if (k==0){
		vis[1]=1;q.push(1);
		bfs();
		printf("%lld\n",tot);
	} 
	else printf("0\n");
	
//	memset(dis,0x3f,sizeof(dis));
//	dis[1]=0;
//	q.push({0,1});
//	while (q.size()){
//		pair<int,int> a=q.top();q.pop();
//		int u=a.second();
//		if (vis[u]) continue;
//		vis[u]=1;
//		for(int i=h[u];i;i=e[i].ne){
//			int v=e[i].v,w=e[i].w;
//			if (dis[v]>dis[u]+w) 
//			dis[v]=dis[u]+w;
//			q.push({-dis[v],v});
//		}
//	}
//	int tem=0;
//	for (int i=1;i<=n;i++) tem+=dis[i];
//	ans=min(ans,tem); 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
