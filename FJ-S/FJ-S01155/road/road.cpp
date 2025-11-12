#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[100010];
queue<pair<int,int> > q;
long long n,m,k,a[1005][1005],c[100010],minn=INT_MAX,ans=0;
bool vis[100010];
int cmp(auto x,auto y){
	return x.second>y.second;
}
void dfs(int k,int sum){
	int ans=0;
	for(int i=0;i<g[k].size();i++){
		if(vis[g[k][i].first]) ans++;
	}
	if(ans==g[k].size()){
		if(sum<minn) minn=sum;
		return;
	}
	vis[k]=1;
	for(int i=0;i<g[k].size();i++){
		if(!vis[g[k][i].first]){
			pair<int,int> ls=g[k][i];
			vis[ls.first]=1;
			dfs(ls.first,sum+ls.second);
			vis[ls.first]=0;
		}
	}
}
void bfs(int k,int sum){
	q.push({1,0});
	vis[1]=1;
	while(!q.empty()){
		int ans=0;
		pair<int,int> ls=q.front(); 
		q.pop();
		int d=ls.first;
		for(int i=0;i<g[d].size();i++){
				if(!vis[g[d][i].first]){
					q.push({g[d][i].first,g[d][i].second+sum});
					sum+=g[d][i].second;
					vis[g[d][i].first]=1;
				}
			}
	}
	if(sum<minn) minn=sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w}); 
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			if(j==0) cin>>c[i];
			else cin>>a[i][j],ans+=a[i][j];
	if(k==0){
		dfs(1,0);
		for(int i=1;i<=n;i++) vis[i]=0;
		bfs(1,0);
		cout<<minn;
	}else{
		cout<<ans;
	}
	return 0;
} 
