#include<bits/stdc++.h>
int n,m,k;
std::vector<std::vector<std::pair<int,int>>> g(100005); 
int ans=0;
bool vis[100005];
void dfs(int u){
	if(vis[u]){
		return;
	} 
	//dfs(u+1);
	vis[u]=1;
	for(auto v:g[u]){
		if(!vis[v.first]){
			vis[v.first]=1;
			ans+=v.second;
			dfs(v.first);
		}
	}
	return ;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		std::cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	int c;
	std::cin>>c;
	for(int i=1;i<=n;i++){
		int a;
		std::cin>>a;
		
	}
	dfs(1);
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
