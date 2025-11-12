#include<bits/stdc++.h>
#define ll long long
ll n,m,k;
ll fa[10004];
using namespace std;
ll find(ll x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
	return;
}
struct node{
	ll u,v,w;
}edge[1000006];
ll edge_cnt;
ll cost[1000006];
ll village[11][10004];
ll bian[10004][10004];
bool cmp(node a,node b){
	return a.w<b.w;
}
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	ll u,v,w;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>w;
		edge[++edge_cnt]={u,v,w};
	}
	for(int i=1;i<=k;++i){
		cin>>cost[i];
		for(int j=1;j<=n;++j) cin>>village[i][j];
		for(int j=1;j<=n;++j){
			for(int p=j+1;p<=n;++p){
				if(village[i][j]+village[i][p]+cost[i]>bian[j][p]) continue;
				edge[++edge_cnt]={j,p,village[i][j]+village[i][p]+cost[i]};
			}
		}
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(edge+1,edge+edge_cnt+1,cmp);
	for(int i=1;i<=edge_cnt;i++){
		if(find(edge[i].u)!=find(edge[i].v)){
			merge(edge[i].u,edge[i].v);
			ans+=edge[i].w; 
		}
	}
	cout<<ans;
	return 0;
}

