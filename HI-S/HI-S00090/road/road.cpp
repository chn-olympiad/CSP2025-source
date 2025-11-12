#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >G[10005];
int n,m,k,ans=1000000005;
int s[10005];
void dfs(int u,int num,int p){
	if(p==n){
		ans=min(ans,num);
		return;
	}
	for(auto v:G[u]){
		if(s[v.first]==0){
			dfs(v.first,num+v.second,p+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		dfs(1,0,0);
	}
	cout<<ans;
	return 0;
}
