#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,u,v,w,f[N][N],c[N],ki[N][12];
struct S{int d,w;};
vector<S> e[N];
bool vis[N],vki[12];
int dfs(int x){
	vis[x]=1;
	int cnt=0,l=e[x].size(),win=1;
	/*for(int i=1;i<=k;++i){
		if(vki[i]){
			for(int j=1;j<=n;++j) if(!vis[j]) cnt+=dfs(i)+ki[j][i];
		}
	}*/
	for(int i=0;i<l;++i){
		if(!vis[e[x][i].d]) cnt+=dfs(vis[e[x][i].d])+e[x][i].w;
	}
	vis[x]=0;
	return cnt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({v,w});
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j) scanf("%d",&ki[i][j]);
	}
	printf("%d",dfs(1));
	return 0;
}
