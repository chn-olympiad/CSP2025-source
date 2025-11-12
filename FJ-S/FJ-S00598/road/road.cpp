#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxe=2e6+5;
int fa[maxn];long long ans;
int findfa(int x){
	return (fa[x]==x?x:findfa(fa[x]));
}
bool chaxun(int x,int y){
	return findfa(x)==findfa(y);
}
void hebing(int x,int y){
	int a=findfa(x),b=findfa(y);
	fa[a]=b;
}

struct edge{
	int u,v;long long w;
}e[maxe];
int n,m,k;long long a[20][maxn],c[20];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			e[++m].u=n+i;
			e[m].v=j;
			e[m].w=a[i][j]+c[j];
		}
	}
	int now,to;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		now=e[i].u;to=e[i].v;
		if(chaxun(now,to)){
			continue;
		}
		else{
			hebing(now,to);
			ans+=e[i].w;
		}
	}
	printf("%lld",ans);
	return 0;
}
