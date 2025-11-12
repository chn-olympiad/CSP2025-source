#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+5;
int n,m,k;
int sum=0;
struct edge{
	int u,v,w;
}e[maxn],g[maxn];
int c[15],a[15][maxn],cnt[maxn],dk=1;
int fa[maxn];
int find(int u){if(u==fa[u])return u; return fa[u]=find(fa[u]);}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int chk[15],ans=1e18+7,sm;
void kruskal(){
	for(int i=1;i<=m;i++)g[i]=e[i];
	sort(g+1,g+m+1,cmp);
	for(int i=1;i<=n+k+1;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=g[i].u,v=g[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv,sum+=g[i].w;		
	}
}
void dfs(int need){
	if(need==k){
		for(int i=1;i<=k;i++){
			if(chk[i]){
				sum+=c[i];
				for(int j=1;j<=n;j++)e[++m]={n+i,j,a[i][j]};
			}
		}
		kruskal();	
		ans=min(ans,sum);
	
		//if(sum==5){
		//	for(int i=1;i<=k;i++)cout<<chk[i]<<' '; cout<<sum<<'\n';
		//}		
		sum=0; m=sm;
		return ;
	}
	chk[need+1]=1; dfs(need+1);
	chk[need+1]=0; dfs(need+1);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; sm=m;
	for(int i=1;i<=k;i++)dk*=2;
	if(dk*m>=1e8){
//		cout<<0<<'\n';
		for(int i=1;i<=k;i++){
			sum+=c[i];
			for(int j=1;j<=n;j++)e[++m]={n+i,j,a[i][j]};		
		}
		kruskal(); ans= sum;
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;

	for(int i=1;i<=k;i++){cin>>c[i];for(int j=1;j<=n;j++)cin>>a[i][j];}
	if(k==0)kruskal(),ans=sum; 
	else dfs(0);
	cout<<ans<<'\n';
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
