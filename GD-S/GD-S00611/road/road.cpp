#include<bits/stdc++.h>
struct node{
	int v,z;
};
std::vector<node> edge[1000010];
int n,m,k,cty[100010];

std::queue<int> q;
bool vis[100010];
int dis[100010],cnt[100010];
int ans;
void dfs(int x,int t,int sums){
	if(sums>=n){
		ans=std::min(ans,t);
		return ;
	}
	for(auto it:edge[x]){
		if(!vis[it.v]){
			vis[it.v]=1;
			dfs(it.v,t+it.z,sums+1);
			vis[it.v]=0;
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		edge[u].push_back({v,z});
		edge[v].push_back({u,z});
	}
	for(int i=1;i<=k;i++){
		int money;
		scanf("%d",&money);
		for(int j=1;j<=n;j++) scanf("%d",&cty[j]),cty[j]+=money;
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(u!=v){
					edge[u].push_back({v,cty[u]+cty[v]-money});
				}
			}
		}
	}
	ans=INT_MAX;
	vis[1]=1;
	dfs(1,0,1);
	printf("%d",ans);
	return 0;
}
