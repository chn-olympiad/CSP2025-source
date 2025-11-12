#include<bits/stdc++.h>
#define INF 2e18
#define fi first
#define se second
#define endl '\n'
#define int long long
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int N = 1e4+5;
const int M = 1e6+5;
const int K = 15; 

int n,m,k,ans,tot;
int fa[N+K],cost[K][N],vis[K];
struct E{int u,v,w;}e1[M],e2[N],e3[N*K];
bool cmp(E x,E y){return x.w<y.w;}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void dfs(int stp){
	if(stp==k+1){
		int res=0,sum=0;
		for(int i=1;i<=tot;i++)e3[++sum]=e2[i];
		for(int i=1;i<=k;i++)if(vis[i]){
			res+=cost[i][0];
			for(int j=1;j<=n;j++)e3[++sum]={n+i,j,cost[i][j]};
		}
		sort(e3+1,e3+sum+1,cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=sum;i++){
			int u=find(e3[i].u),v=find(e3[i].v),w=e3[i].w;
			if(u==v)continue;
			res+=w,fa[u]=v;
		}
		ans=min(ans,res);
		return;
	}
	dfs(stp+1),vis[stp]=1,dfs(stp+1),vis[stp]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>e1[i].u>>e1[i].v>>e1[i].w;
	for(int i=1;i<=k;i++){
		cin>>cost[i][0];
		for(int j=1;j<=n;j++)cin>>cost[i][j];
	}
	sort(e1+1,e1+m+1,cmp);
	for(int i=1;i<=m;i++){
		int x=find(e1[i].u),y=find(e1[i].v),w=e1[i].w;
		if(x==y)continue;
		fa[x]=y,ans+=w,e2[++tot]=e1[i];
		if(tot==n-1)break;
	}
	dfs(1),cout<<ans;
	return 0;
} 
/*
15:50 想到思路 
16:09 样例通过 
16:11 大数据通过 100pts 
*/
