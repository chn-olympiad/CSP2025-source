#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10010;
int n,m,k;
struct node{
	int u,v,w;
};
bool operator<(node x,node y){
	return x.w<y.w;
}
vector<node>e;
int c[11];
int a[11][N];
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back({u,v,w});
		e.push_back({v,u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		int id=-1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)id=j;
		}
		for(int j=1;j<=n;j++){
			if(id==j)continue;
			e.push_back({id,j,a[i][j]});
			e.push_back({j,id,a[i][j]});
		}
	}
	stable_sort(e.begin(),e.end());
	for(int i=1;i<=n;i++)fa[i]=i;
	ll ans=0;
	for(int i=0;i<(int)e.size();i++){
		int u=e[i].u,v=e[i].v;
		u=find(u),v=find(v);
		if(u==v)continue;
		ans+=e[i].w;
		fa[u]=v;
	}
	printf("%lld",ans);
	return 0;
}
