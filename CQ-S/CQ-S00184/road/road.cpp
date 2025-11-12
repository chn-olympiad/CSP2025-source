#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+10;
const int maxm=1e6+10;
int n,m,k,tot;
ll ans;

struct Edge{
	int u,v;
	ll w;
}e[maxm+11];
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

int f[maxn];
int find(int u){
	return f[u]==u?u:f[u]=find(f[u]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1;i<=k;i++){
		int c,w,u,v,min1,min2;
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			if(!min1) min1=w;
			else if(min1&&!min2){
				if(min1>w) min2=min1,min1=w,u=2,v=1;
				else min2=w,u=1,v=2;
			}
			else if(min1>w) min2=min1,v=u,min1=w,u=j;
			else if(min2>w) min2=w,v=j;
		}
		e[++m]={u,v,min1+min2+c};
	}
		for(int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			f[find(e[i].u)]=find(e[i].v);
			ans+=e[i].w;
			if(++tot==n-1) break;
		}
		}
		printf("%lld",ans);
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
