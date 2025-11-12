#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[10005][10005],p[15][10005],e[10005],u,v,w;
long long h;
struct g{
	int u,v,w;
}d[10005];
int c(g x,g y){
	return x.w<y.w;
}
int main(){
	freopen("road2.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		s[u][v]=w;//邻接表 
		s[v][u]=w;
		d[i].u=u;//数组 
		d[i].v=v;
		d[i].w=w;
	}
	sort(d,d+m,c);
	for(int j=0;j<k;j++){
		cin>>p[j][0];
		for(int i=1;i<=n;i++)cin>>p[j][i];
	}
	for(int i=0;i<m;i++){
		if(e[d[i].u]==0||e[d[i].v]==0){
			e[d[i].u]=1;
			e[d[i].v]=1;
			h+=d[i].w;
		}
	}
	cout<<h;
}
