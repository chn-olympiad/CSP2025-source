#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+5,M=15;
int n,m,k,ans,tot,all;
int fa[N],now[M],c[N],a[M][N];
struct NODE{
	int u,v,w;
}g[N],e[N];

int fnd(int x){
	return x==fa[x]?x:fa[x]=fnd(fa[x]);
}
bool cmp(NODE &a,NODE &b){
	return a.w<b.w;
}
void kruskal(){
	sort(e+1,e+all+1,cmp);
	int pt=n+tot;
	for(int i=1;i<=pt;i++)
		fa[i]=i;
	for(int i=1;i<=all;i++){
		int u=fnd(e[i].u),v=fnd(e[i].v);
		if(u!=v){
			ans+=e[i].w;
			fa[u]=v;
			pt--;
			if(pt==1)
				return;
		}
	}
}
void solve(){
	all=m,tot=k;
	for(int i=1;i<=m;i++)
		e[i]=g[i];
	for(int j=1;j<=k;j++)
		for(int k=1;k<=n;k++)
			e[++all]={n+j,k,a[j][k]};
	kruskal();
	cout<<ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[i]={u,v,w};
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i])
			f=0;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(f){
		solve();
		return 0;
	}
	int Ans=1e18;
	for(int i=0;i<(1<<k);i++){
		tot=0;
		for(int j=0;j<k;j++)
			if((i>>j)&1)
				now[++tot]=j+1;
		ans=0;
		for(int j=1;j<=tot;j++)
			ans+=c[now[j]];
		all=m;
		for(int j=1;j<=m;j++)
			e[j]=g[j];
		for(int j=1;j<=tot;j++)
			for(int k=1;k<=n;k++)
				e[++all]={n+now[j],k,a[now[j]][k]};
		kruskal();
		Ans=min(Ans,ans);
	}
	cout<<Ans;
	return 0;
}

