#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
struct node{
	int to,w,flg;
};
vector<vector<node>> adj;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,w_;
	int ans=0;
	adj.resize(n+1);
	for(int i=1;i<=m;i++){
		cin>>x>>y>>w_;
		adj[x].push_back({y,w_,0});
		adj[y].push_back({x,w_,0});
	}
	for(int i=1;i<=n-1;i++){
		int mn=1e9,wz;
		for(int j=0;j<adj[i].size();j++){
			if(mn>adj[i][j].w&&adj[i][j].flg==0){
				mn=adj[i][j].w;
				wz=j;
			}
		}
		ans+=mn;
		adj[i][wz].flg=1;
		adj[wz][i].flg=1;
	}
	cout<<ans;
	return 0;
}
