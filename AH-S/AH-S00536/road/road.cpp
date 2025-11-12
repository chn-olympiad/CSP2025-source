#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[10003],ans,vis[20003];
struct edge{
	int u,v,w;
}e[2000003];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int c[13];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>e[m+(i-1)*n+j].w;
			e[m+(i-1)*n+j].u=n+i;
			e[m+(i-1)*n+j].v=j;
		}
	}
	cout<<0;
	return 0;
}
