//zui xiao sheng cheng shu
#include<bits/stdc++.h>
#define N 10000
using namespace std;
/*
int n,m,k;
struct edge{int x,v;};
vector<edge>G[N];
int c[N],a[15][N];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	
	return 0;
}*/
int n,m,k,cnt;
long long ans;
int fa[N];
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void bind(int x,int y){
	x=find(x),y=find(y);
	fa[y]=x;
}
struct edge{int x,w,y;};
vector<edge>a;
bool cmp(edge a,edge b){return a.w<b.w;}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a.push_back({u,w,v});
	}
	for(int i=1;i<=k;i++){
		int w;
		scanf("%d",&w);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			if(w==0)bind(i,j);
			else 
				a.push_back({i,w,j});
		}
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
		int x=a[i].x,w=a[i].w,y=a[i].y;
		if(find(x)==find(y))continue;
		fa[find(y)]=find(x);
		ans+=w;
		if(cnt++==n-1)break;
	}
	cout<<ans;
	return 0;
}

