#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct UFS{
	int f[N],sz[N];
	void init(int n){for(int i=1;i<=n;i++){f[i]=i;sz[i]=1;}return;}
	int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
	void merge(int x,int y){x=find(x);y=find(y);if(x==y)return;if(sz[x]<sz[y])swap(x,y);f[y]=x;sz[x]+=sz[y];return;}
}ufs;
struct Edge{
	int u,v,w;
}e[M],ne[M];
int n,m,wk[15][N],c[15],tot,k;
long long ans; 
void init(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>wk[i][j];
	}
	return;
}
bool cmp(Edge A,Edge B){
	return A.w<B.w;
}
void kruskal(){
	sort(e+1,e+1+m,cmp);
	ufs.init(n);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(ufs.find(u)==ufs.find(v))continue;
		tot++;
		ne[tot].u=u;
		ne[tot].v=v;
		ne[tot].w=w;
		ufs.merge(u,v);
		ans+=w;
		if(tot==n-1)break;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	kruskal();
	cout<<ans<<"\n";
	return 0;
}

