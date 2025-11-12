#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1000000000000000000;
ll n,m,k,a[15][20005],r,C[15],rr,fa[20005],ans,ret;
struct node{
	ll u,v,w;
}c[2000005],d[200005],g[200005];
int cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>c[i].u>>c[i].v>>c[i].w;
	}
	sort(c+1,c+m+1,cmp);
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(find(c[i].u)!=find(c[i].v)){
			fa[find(c[i].u)]=find(c[i].v);
			d[++r]=c[i];
		}
	}
	ans=inf;
	for(ll i=1;i<=k;i++){
		cin>>C[i];
		for(ll j=1;j<=n;j++){
			cin>>a[i][j];
			++r;
			d[r].u=j;
			d[r].v=i+n;
			d[r].w=a[i][j];
		}
	}
	sort(d+1,d+r+1,cmp);
	for(ll i=0;i<(1ll<<k);i++){
		rr=0;
		for(ll j=1;j<=r;j++){
			int qs=d[j].v-n;
			if(qs>=1){
				if((i>>(qs-1))&1){
					g[++rr]=d[j];
				}
			}
			else{
				g[++rr]=d[j];
			}
		}
		ret=0;
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				ret+=C[j+1];
			}
		}
		for(int j=1;j<=rr;j++){
			if(find(g[j].u)!=find(g[j].v)){
				fa[find(g[j].u)]=find(g[j].v);
				ret+=g[j].w;
			}
		}
		ans=min(ans,ret);
	}
	cout<<ans;
	return 0;
}
