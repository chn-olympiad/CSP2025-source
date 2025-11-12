#include <bits/stdc++.h>
using namespace std;
int n,m,k,tot;
int c[10000];
int f[1001];
long long ans;
struct edge{
	int u,v,w;
}e[2000001],g[1000001];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int u){
	if(f[u]!=u) return f[u]=find(f[u]);
	return f[u];
}
void unio(int u,int v){
	int U=find(u);int V=find(v);
	f[U]=V;
}
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
scanf("%d%d%d",&n,&m,&k);
for(int i=0;i<m;i++){
	scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
}
for(int i=1;i<=n;i++){
	f[i]=i;
}
sort(e,e+m,cmp);
for(int i=0;i<m;i++){
	
	int u=e[i].u;int v=e[i].v;
	
	if(find(u)==find(v)) continue;
	ans+=e[i].w;
	tot++;
	unio(u,v);
	if(tot==n-1) break;
}
cout << ans;
return 0;
}
