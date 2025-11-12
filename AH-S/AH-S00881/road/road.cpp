#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
};
vector<vector<node>> fuck;
const int mct=1e9+5;
bool vt[100005];
bool check(){
	for(int i=2;i<=n;i++){
		if(vt[i]!=true){
			return false;
		}
	}
	return true
}
}void dfs(int idex,int ct){
	if(check()){
		mct=min(mct,ct);
		return;
	}int sz=fuck[idex].size;
	for(int i=0;i<sz;i++){
		if(vis!=fuck[idex][i].a){
			vis[idex]=true;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	fuck.resize(n+1);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		fuck[u].push_back({v,u});
		fuck[u].push_back({u,v});
	}for(int i=1;i<+k;i++){
		int nb;
		cin>>nb;
		for(int j=1;j<=n;j++){
			int ct; cin>>ct;
		}
	}
	return 0;
}
