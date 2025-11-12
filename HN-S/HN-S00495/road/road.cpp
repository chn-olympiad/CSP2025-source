#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010
#define MAXK 15
int n,m,k,c[MAXK][MAXN],fa[MAXN],size[MAXN],ans,vis[MAXK];
struct edge{
	int to,cost;
	edge(int t=0,int c=0):to(t),cost(c){}
};
struct edge2{
    int from,to,cost;
	edge2(int f=0,int t=0,int c=0):from(f),to(t),cost(c){}
}a[MAXN];
vector<edge> g[MAXN];

bool cmp(edge2 a,edge2 b){
	return a.cost<b.cost;
}
void addedge(int u,int v,int w){
	g[u].push_back(edge(v,w));
	g[v].push_back(edge(u,w));
}

void init(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		a[i]=edge2(u,v,w);
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			scanf("%d",&c[i][j]);
	for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
}

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void join(int c1,int c2){
	int f1=find(c1),f2=find(c2);
	if(f1!=f2){
		if(size[f1]<size[f2])swap(f1,f2);
		fa[f2]=f1;
		size[f1]+=size[f2];
	}
}

void kruskal(){
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		edge2 now=a[i];
		if(find(fa[now.from])!=find(fa[now.to])){
			ans+=now.cost;
			if(size[now.from]+size[now.to]==n)break;
			join(now.from,now.to);
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	kruskal();
	printf("%d",ans);
	return 0;
}
