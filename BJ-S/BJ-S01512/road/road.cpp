#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int to,val;
};
vector<Node> G[10010];
void prim(){
	cout<<"I don't konw!!!";
}
int main(){
	freopen();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	if(k==0) dij();
}
