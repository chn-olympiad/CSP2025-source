#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int S=1e3+5;
int n,m,k;
struct edge{
	int u,v;
	long long w;
}e[M];
int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return false;
	fa[y]=x;
	return true;
}
bool cmp(edge xx,edge yy){
	return xx.w<yy.w;
}
long long kruskal(int m){
	sort(e+1,e+1+m,cmp);
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)){
			cnt++;
			ans+=e[i].w;
		}	
		if(cnt==n-1)break;
	}
	return ans;
}
int c[11];
int a[11][N];
long long dis[S][S];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		cout<<kruskal(m);
		return 0;
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
		dis[u][v]=dis[v][u]=w;
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)f=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(f){
		for(int i=1;i<=k;++i){
			for(int v=1;v<=n;++v){
				e[++m]={i+n,v,a[i][v]};
			}
		}
		cout<<kruskal(m);
	}
	return 0;
}