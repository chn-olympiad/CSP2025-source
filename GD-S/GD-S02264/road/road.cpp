#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=10002,M=1000002,K=12;


struct EDGE{
	int u,v,w;
}edge[M],e[M*10];

bool cmp(EDGE a,EDGE b){
	return a.w<b.w;
}

int tot=0;
void add(int u,int v,int w){
	e[++tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
}

int fa[N];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void unio(int x,int y){
	x=find(x);y=find(y);
	if(x!=y) fa[x]=y;
}

int c[K];
int dis[N];

bool cmp2(EDGE a,EDGE b){
	return a.w>b.w;
}

void init(){
	int cnt=0;
	for(int i=1;i<=tot;i++){
		if(e[i].u!=0) e[++cnt]=e[i];
	}
	tot=cnt;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long mst=0;
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(find(u)!=find(v)){
			mst+=w;
			unio(u,v);
			add(u,v,w);
		}
	}
//	sort(e+1,e+1+tot,cmp);

//	cout<<mst;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		
		long long ans=c[i];
		for(int j=1;j<=n;j++) cin>>dis[j];

	}
	cout<<mst;
	
	
	
	
	return 0;
}
