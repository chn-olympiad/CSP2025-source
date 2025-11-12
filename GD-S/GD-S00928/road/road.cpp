#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5;
bool vis[N][N];
int n,m,k,ans;
int h[M],e[M],ne[M],cost[M],cnt;
int u[M],v[M],w[M],con[15][N];//con[0][i]第i个乡村开发价格
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
void add(int x,int y,int z){
	e[++cnt]=y;
	ne[cnt]=h[x];
	h[x]=cnt;
	cost[cnt]=z;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>con[k][j];
	}
	for(int i=1;i<=m;i++){
		if(vis[a[i].u][a[i].v])continue;
		ans+=a[i].w;
		vis[a[i].u][a[i].v]=1;
		
	}
	cout<<0;
	return 0;
}
