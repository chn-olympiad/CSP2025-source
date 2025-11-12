#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int n,m,k,t,h[11],b[11][N/10],f[N],siz[N],r=1e18;
bool v;
struct dd{int u,v,w;}a[N];
bool p(dd a,dd b){return a.w<b.w;}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void mg(int x,int y){
	if(siz[x]>siz[y])f[y]=x,siz[x]+=siz[y];
	else f[x]=y,siz[y]+=siz[x];
}
void dfs(int c,int w,int t){
	for(int i=1; i<=n+k; i++)f[i]=i,siz[i]=0;
	sort(a+1,a+m+1,p);int s=w;
	for(int i=1; i<=m; i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v){
			mg(u,v);
			s+=a[i].w;
		}
	}
	r=min(r,s);
	for(int l=c+1; l<=k; l++){
		for(int i=1; i<=n; i++)a[++m]={t+n+1,i,b[l][i]};
		dfs(l,w+h[l],t+1);m-=n;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	//for(int i=1; i<=n+k; i++)f[i]=i;
	for(int i=1; i<=m; i++)scanf("%lld%lld%lld", &a[i].u,&a[i].v,&a[i].w);
	for(int i=1; i<=k; i++){
		scanf("%lld", &h[i]);
		if(h[i])v=1;
		for(int j=1; j<=n; j++){
			scanf("%lld", &b[i][j]);
			if(b[i][j])v=1;
		}
	}
	if(!v){
		printf("0");
		return 0;
	}
	/*
	sort(a+1,a+m+1,p);
	for(int i=1; i<=m; i++){
		int u=find(a[i].u),v=find(a[i].v);
		if(u!=v){
			mg(u,v);
			r+=a[i].w;
		}
	}*/
	for(int )
	dfs(0,0,0);
	printf("%lld", r);
	return 0;
}
