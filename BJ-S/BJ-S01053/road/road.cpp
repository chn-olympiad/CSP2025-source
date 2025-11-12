#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50;
int c[N],n,m,k;
long long ans=1e18;
struct node{
	int v,w;
};
vector<node> g[N];
int s[N];
bool vis[N];
void dfs(int u,int cnt,long long sum){
	s[cnt]=u;
	if(cnt==n){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<g[u].size();i++){
		int a=g[u][i].v,b=g[u][i].w;
		if(!vis[a]){
			vis[a]=1;
			dfs(a,cnt+(a>n?0:1),sum+b);
			vis[a]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back((node){v,w});
		g[v].push_back((node){u,w});
	}
	int w;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			g[i+n].push_back((node){j,w});
			g[j].push_back((node){i+n,w+c[j]});
		}
	}
	vis[1]=1;
	dfs(1,1,0);
	printf("%lld",ans);
}