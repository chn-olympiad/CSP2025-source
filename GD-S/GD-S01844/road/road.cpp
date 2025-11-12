#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,N,k,b[14],e[14],c[14][10005],w[14][10005],pre[20005];
ll s,mn=1e18;
struct xx{int u,v,w;}a[2000005];
struct yy{int u,v,w;}A[2000005];
int cmp(yy x,yy y){return x.w<y.w;}
int mpc(xx x,xx y){return x.w<y.w;}
int find(int d){
	if(d==pre[d]) return d;
	return pre[d]=find(pre[d]);
}
void js(){
	N=m,s=0;
	for(int i=1;i<=n+k;i++) pre[i]=i;
	for(int i=1;i<=m;i++) A[i]={a[i].u,a[i].v,a[i].w};
	for(int i=1;i<=k;i++){
		if(!e[i]) continue;
		s+=b[i];
		for(int j=1;j<=n;j++) A[++N].u=i+n,A[N].v=j,A[N].w=c[i][j];
	}
	sort(A+1,A+1+N,cmp);
	for(int i=1;i<=N;i++){
		int u=find(A[i].u),v=find(A[i].v);
		if(u!=v) pre[u]=v,s+=A[i].w;
		if(s>=mn) break;
	}
	mn=min(mn,s);
}
void dfs(int d){
	if(d>k){js();return;}
	for(int i=0;i<2;i++){
		if(!b[d]&&i) continue;
		e[d]=i,dfs(d+1);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			if(!b[i]) a[++m].u=i+n,a[m].v=j,a[m].w=c[i][j];
		}
	}
	dfs(1),printf("%lld",mn);
	return 0;
}
