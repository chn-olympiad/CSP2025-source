#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[11][10010],c[11],f[10010];
struct edge{int u,v,w;}e[N];
int find(int u){
	if(f[u]==u)return u;
	return f[u]=find(f[u]);
}bool cmp(edge a,edge b){return a.w<b.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}sort(e+1,e+1+m,cmp);
	int res=0;	
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		f[u]=v;res+=e[i].w;
	}cout<<res;
	return 0;
}

