#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+25;
struct node{
	int to,nxt,w;
}edge[N<<1];
int head[N],tot;
inline void add(int u,int v,int w){
	edge[++tot]=(node){v,head[u],w};
	head[u]=tot;
	//edge[i]=(node){u,head[v],w};
	//head[v]=tot;
}
int n,m,k,ans;
int f[N],dis[N],c[15];
bool vis[N];
vector<int> mp;
inline int find(int u){
	return f[u]==u?u:f[u]=find(f[u]);
}
inline bool check(){
	for(int i=2;i<=n;++i){
		if(f[i]!=f[1]) return false;
	}
	return true;
}
inline void dij(){
	fill(dis+1,dis+n+1,INT_MAX);
	memset(vis,false,sizeof vis);
	queue<int> q;
	q.push(1);
	dis[1]=0;
	vis[1]=true;
	while(!q.empty()){
		int u=q.back();
		q.pop();
		if(check()){
			ans=dis[u];
		}
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(vis[v]) continue;
			if(dis[u]+edge[i].w<dis[v]){
				dis[v]=edge[i].w+dis[u];
				f[find(v)]=f[find(u)];
				vis[v]=true;
				q.push(v);
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n+k;++i) f[i]=i;
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%lld %lld %lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		printf("%lld %lld %lld\n",u,v,w);
	}
	for(int i=n+1;i<=n+k;++i){
		scanf("%lld",&c[i-n]);
		for(int j=1,a;j<=n;++j){
			scanf("%lld",&a);
			add(i,j,a);
			add(j,i,a);
		}
	}
	dij();
	for(int i=n+1;i<=n+k;++i){
		if(vis[i]) ans+=c[i-n];
	}
	printf("%lld",ans);
	return 0;
}
