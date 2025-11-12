#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
vector<int> g[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int v,u,w;
		cin>>v>>u>>w;
		g[u].push_back(v);
		g[v].push_back(u); 
	}
	return 0;
