#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct note{
	int v,w;
};
vector<note> a[100010];
void dfs(int x,int y){
	
}
int u,v,w;
int main(){
	freopen("road.in","r",stdin);
	freopen("raod.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		cin>>u>>v>>w;
		a[u].push_back({u,w});
		a[v].push_back({u,w});
	}
	return 0;
}
