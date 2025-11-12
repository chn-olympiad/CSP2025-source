#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
struct node{
	int u,v,w;
}r[1100010];
int n,m,k,u,v,w,tot,ant,bs;
int fa[10010],c[15],len[15][10010];
bool cmp(node x,node y){
	if(x.w!=y.w){
		return x.w<y.w;
	}
	return x.u<y.u;
}
int find(int u){
	if(fa[u]==u){
		return u;
	}
	return fa[u]=find(fa[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	tot=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>len[i][j];
			r[++tot].u=n+i;
			r[tot].v=j;
			r[tot].w=len[i][j];
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	sort(r+1,r+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		if(fa[find(r[i].u)]!=fa[find(r[i].v)]){
			fa[find(r[i].u)]=fa[find(r[i].v)];
			ant+=r[i].w;
			bs++;
			if(bs==n+k-1){
				break;
			}
		}
	}
	cout<<ant<<"\n";
	return 0;
}