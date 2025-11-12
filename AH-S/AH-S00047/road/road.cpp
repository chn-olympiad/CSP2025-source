#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef struct Edge{
	int u,v; ll w;
	Edge(){}
	Edge(int _u,int _v,ll _w):u(_u),v(_v),w(_w){}
	bool operator<(const Edge& x)const{
		return w<x.w;
	}
} edge;
const int N=1e4+5,M=1e3+5,K=15;
set<edge> E;
int fa[N],a[K][N],n,m,k,u,v;
ll w,mp[M][M],ans=0;
inline int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(mp,-1,sizeof(mp));
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		E.insert(edge(u,v,w));
		if(k) mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		ll x; cin>>x;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
		ll tot=0;
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++)
				if(~mp[j][l]&&mp[i][j]+mp[i][l]<mp[j][l])
					tot+=mp[j][l]-mp[i][j]-mp[i][l];
		}
		if(tot>x) ans-=tot-x;
	}
	for(auto& p:E){
		u=p.u,v=p.v,w=p.w;
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v),ans+=w;
	}
	cout<<ans<<"\n";
	return 0;
}
