#include <bits/stdc++.h>
using namespace std;
struct node{
	int city,pay;
};
int n,m,k;
int ans;
vector<node> ve[10005];
int c[20][10005];
bool vis[10005][10005];
bool viss[10005];
bool check(){
	queue<int> q;
	q.push(1);
	while(q.size()){
		int r=q.front();
		q.pop();
		viss[r]=1;
		for(int i=0;i<ve[r].size();i++){
			if(!viss[ve[r][i].city]){
				q.push(ve[r][i].city);
			}
		}
	}
	return q.empty();
}
int summ(){
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<ve[i].size();j++){
			if(vis[i][ve[i][j].city]){
				sum+=ve[i][j].pay;
			}
		}
	}
	return sum;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			ans=min(ans,summ());
		}
		memset(viss,0,sizeof(viss));
		return;
	}
	for(int i=0;i<ve[x].size();i++){
		if(!vis[x][ve[x][i].city]){
			vis[x][ve[x][i].city]=1;
			dfs(x+1);
			vis[x][ve[x][i].city]=0;
		}
		dfs(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
