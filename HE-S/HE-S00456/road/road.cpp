#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int u,v,w;
	edge (int x,int y,int z){
		u=x,v=y,w=z;
	}
	bool operator < (const edge &A){
		return w<A.w;
	}
};
vector<edge> edges;
int n,m,k,c[11],a[11][100010],d[10010][10010];
int fa[1000010];
int findfa(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=findfa(fa[x]);
}int ans=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back(edge(u,v,w));	
	}
	
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			d[i][j]=LLONG_MAX;
			for(int l=1;l<=k;l++)
				d[i][j]=min(d[i][j],a[l][i]+a[l][j]+c[l]);
			edges.push_back(edge(i,j,d[i][j]));
		}
	}

	sort(edges.begin(),edges.end());
	int l=edges.size();
	int x=n;

	for(int i=0;i<l;i++){
		if(x==1){
			break;
		}
		int u=edges[i].u;
		int v=edges[i].v;
		int w=edges[i].w;
		int x=findfa(u);
		int y=findfa(v);
		if(x!=y){
			fa[x]=fa[y];
			ans+=w;x-=1;
		}	
	}
	cout<<ans;
}
	
