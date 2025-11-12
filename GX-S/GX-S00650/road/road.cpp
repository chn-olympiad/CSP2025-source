#include <bits/stdc++.h>
using namespace std;
vector<int> t[10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		t[u].push_back(v);
		t[v].push_back(u);
	}
	
	return 0;
}
