#include<bits/stdc++.h>
using namespace std;
const int N=1e9;
int m,n,k,ans=N;
vector<pair<int,int> >a1[1000010];
int vis[100010];
void dfs(int node,int step,int spend){
	if(step==n){
		ans=min(ans,spend);
		return;
	}
	for(auto i:a1[node].first){
		if(vis[a1[i].first])==0){
			vis[a1[i].first]=1;
			dfs(i,step+1,spend+a[i].first);
			vis[a1[i].first]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a1[u].push_back(v,w);
		a1[v].push_back(u,w);
	}
	int c;
	cin<<c;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(i,0,a[i].first);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
