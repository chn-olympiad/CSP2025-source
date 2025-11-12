#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a;
vector<bool>vis;
int n,m,k;
struct node{
	int x,w;
};
int ans=INT_MAX;
bool check(){
	for(int i=1;i<=n;i++){
		if(!vis[i])return false;
	}
	return true;
}
int now;
void dfs(int x){
	//cout<<x<<" "<<now<<endl;
	if(check()){
		ans=min(ans,now);
		//cout<<now<<" ";
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			now+=a[x][i]; 
			dfs(i);
			now-=a[x][i];
			vis[i]=false;
		}
	}
}
void bfs(){
	queue<pair<int,int>>q;
	q.push({1,0});
	while(!q.empty()){
		pair<int,int>u=q.front();
		q.pop();
		//cout<<u.first<<" "<<u.second<<endl;
		if(check()){
			ans=min(ans,u.second);
		}
		for(int i=1;i<=n;i++){
			//if(!vis[i]){
			//	vis[i]=true;
				q.push({i,u.second+a[u.first][i]});
		//	}
		}
	}
}
void solve(){
	cin>>n>>m>>k;
	a.resize(n+k+5,vector<int>(n+k+5));
	vis.resize(n+k+5);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		int t;
		cin>>t;
		vector<int>t2(n+5);
		for(int j=1;j<=n;j++){
			cin>>t2[j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(!a[i][j]){
					a[i][j]=t2[i]+t2[j]+t;
				}else{
					a[i][j]=min(a[i][j],t2[i]+t2[j]+t);
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			if(i!=j)cout<<i<<" "<<j<<": "<<a[i][j]<<endl;
//		}
//	}
	dfs(0);
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}

