#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
struct edge{
	int u,v;
	long long w;
};
edge e[1000005];
int col[10005];
vector<int> adj[10005];
int fa[10005];
int c[15];
long long a[15][10005];
bool cmp1(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x])
		return x;
	return find(fa[x]);
}
void kruscal(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+1,e+m+1,cmp1);
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			fa[find(e[i].v)]=find(e[i].u);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i].u=u;
		e[i].v=v;
		e[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0){
		kruscal();
		cout<<ans;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
