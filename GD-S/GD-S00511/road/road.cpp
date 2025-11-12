#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[10005];
int u,v,w;
struct node{
	int v,w;
};
vector<node>g[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	cin >> n >>m >>k;
	for(int i=1;i<=n;i++){
		cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
	}
	return 0;
} 
// 3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0

