#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int read(){
	int x=0;bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}

int n,m,k,c[15][1005];
int g[1005][1005];

struct edge{
	int u,v,w;
}ed[2000005];

int tot;

bool cmp(edge a,edge b){
	return a.w<b.w;
}

int fa[1105];

int findd(int x){
	if(x==fa[x])return x;
	return fa[x]=findd(fa[x]);
}

long long ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=inf;
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		g[u][v]=min(g[u][v],w);
		g[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		c[i][0]=read();
		for(int j=1;j<=n;j++){
			c[i][j]=read();
		}
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				g[u][v]=min(g[u][v],c[i][u]+c[i][v]);
				g[v][u]=g[u][v];
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			ed[++tot].u=i;
			ed[tot].v=j;
			ed[tot].w=g[i][j];
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(ed+1,ed+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		int fu=findd(ed[i].u),fv=findd(ed[i].v);
		if(fu==fv)continue ;
		fa[fu]=fa[fv];
		ans+=ed[i].w;
	}
	printf("%lld",ans);
	return 0;
}
