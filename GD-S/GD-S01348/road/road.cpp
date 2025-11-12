#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 1000010
using namespace std;
int n,m,m1,k,fa[N],vis[N],tot;
ll ans,sum,c[15][N];
int cx(int x){
	if(x==fa[x])return x;
	return fa[x]=cx(fa[x]);
}
struct E{
	int u,v;
	ll w;
}e0[N*2],e[N*2],e1[N*2];
bool cmp(E x,E y){
	return x.w<y.w;
}
void init(){
	int cntnode=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=cx(e0[i].u),v=cx(e0[i].v);
		if(u==v)continue;
		ans+=e0[i].w;
		cntnode++;
		fa[v]=u;
		e[++m1]=e0[i];
		if(cntnode==n-1)break;
	}
	return;
}
void calc(){
	int cntnode=n;
	sum=0;
	tot=m1;
	for(int i=1;i<=m1;i++)
		e1[i]=e[i];
	for(int i=1;i<=k;i++)
		if(vis[i]){
			cntnode++;
			sum+=c[i][0];
			for(int j=1;j<=n;j++)
				e1[++tot]={i+n,j,c[i][j]};
		}
	sort(e1+1,e1+tot+1,cmp);
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=tot;i++){
		int u=cx(e1[i].u),v=cx(e1[i].v);
		if(u==v)continue;
		sum+=e1[i].w;
		fa[v]=u;
		cntnode--;
		if(cntnode==1)break;
	}
	ans=min(ans,sum);
}
void dfs(int nw){
	if(nw==k+1){
		calc();
		return;
	}
	vis[nw]=0;
	dfs(nw+1);
	vis[nw]=1;
	dfs(nw+1);
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e0[i].u>>e0[i].v>>e0[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	sort(e0+1,e0+m+1,cmp);
	init();
	dfs(1);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
