#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,kk,c[13],a[13][1010];
int ans;

int g[5010][5010];

struct edge{
	int u,v;
}e[2000010];
int tot;

void add(int u,int v){
	e[++tot]={u,v};
}

bool cmp(edge e1,edge e2){
	return g[e1.u][e1.v]<g[e2.u][e2.v];
}

int fa[1010];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}

void kruskal(){
	init();
	for(int i=1;i<=tot;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v))continue;
		ans=ans+g[u][v];
		fa[find(u)]=find(v);
	}
}

int in(){
	char c=getchar();
	int num=0;
	while(!('0'<=c&&c<='9')&&c!=EOF)c=getchar();
	while(('0'<=c&&c<='9')&&c!=EOF){
		num=num*10+c-'0';
		c=getchar();
	}
	return num;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=in();
	m=in();
	kk=in();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=2e9;
	for(int i=1,u,v,w;i<=m;i++){
		u=in();
		v=in();
		w=in();
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	for(int i=1;i<=kk;i++){
		c[i]=in();
		for(int j=1;j<=n;j++){
			a[i][j]=in();
			for(int k=1;k<j;k++){
				g[k][j]=min(g[k][j],a[i][j]+a[i][k]);
				g[j][k]=min(g[j][k],a[i][j]+a[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			add(i,j);
		}
	}
	sort(e+1,e+tot+1,cmp);
	kruskal();
	printf("%lld",ans);
	
	return 0;
}
