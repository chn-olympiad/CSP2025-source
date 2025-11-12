#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e6+5;
int n,m,k,f[N],l,a[15][N],c[15],ans,w[N][N];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}struct node{int u,v,c;}e[M];
bool cmp(node&q,node&w){return q.c<w.c;}
void kruskal(){
	sort(e+1,e+1+l,cmp);
	for(int i=1;i<=l;i++){
		int eu=find(e[i].u),ev=find(e[i].v),w=e[i].c;
		if(eu==ev)continue;
		f[ev]=eu;
		ans+=w;
	}
}int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	memset(w,0x3f3f3f3f,sizeof w);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>e[++l].u>>e[l].v>>e[l].c;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		for(int j=1;j<=n;j++)for(int u=1;u<=n;u++)if(j!=u)w[u][j]=w[j][u]=min(a[i][u]+a[i][j],w[j][u]);
	}for(int i=1;i<=n;i++)for(int j=1;j<i;j++)if(i!=j){
		e[++l].u=i;
		e[l].v=j;
		e[l].c=w[i][j];
	}kruskal();
	cout<<ans<<'\n';
	return 0;
}
