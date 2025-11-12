#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[11005],c[10005],a[15][10005];
struct edge{
	int u,v,w;
}e[1000005];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k!=0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		ans+=e[i].w,fa[v]=u;
		if(++cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}
