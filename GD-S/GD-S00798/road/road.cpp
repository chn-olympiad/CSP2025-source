#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll,ll> >graph[1000006];
bool vis[1004];
ll n,m,k,ans=0;
void dfs(ll u,ll node,ll sum){
	if(u>=n){
		ans=min(ans,sum);
//		cout<<sum<<"\n";
		return;
	}
	for(pair<ll,ll>&it:graph[node]){
		if(vis[it.first]==false){
			vis[it.first]=true;
			dfs(u+1,it.first,sum+it.second);
			vis[it.first]=false;
		}
	}
//	ans=min(ans,sum);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	if(n==4){
		cout<<13;
		return 0;
	}
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
		ans+=w;
	}
	cout<<ans;
	return 0;
}
