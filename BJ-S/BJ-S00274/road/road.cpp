#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c[30][50010],f[50010],fa[50010],ans=0x3f3f3f3f,vis[50010];
bool use[50010];
struct node{
	ll x,y,z;
}G[50000],B[50000];
bool cmp(node x,node y){
	return x.z<y.z;
}
ll find(ll x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void dfs(ll x){
	if(x==k+1){
		ll tot=m,ne=n,cost=0;
		for(int i=1;i<=k;i++){
			if(use[i]==1){
				ne++;
				cost+=f[i];
				for(int j=1;j<=n;j++){
					G[++tot]={ne,j,c[i][j]};
				}
			}
		}
		sort(G+1,G+tot+1,cmp);
		for(int i=1;i<=ne;i++) fa[i]=i;
		for(int i=1;i<=tot;i++){
			if(find(G[i].x)!=find(G[i].y)){
				fa[find(G[i].x)]=find(G[i].y);
				cost+=G[i].z;
			}
		}
		ans=min(ans,cost);
		return ;
	}use[x]=0;
	dfs(x+1);
	use[x]=1;
	dfs(x+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>G[i].x>>G[i].y>>G[i].z;
	}for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int j=1;j<=n;j++){cin>>c[i][j];}
	}dfs(1);
	cout<<ans;
	return 0;
}