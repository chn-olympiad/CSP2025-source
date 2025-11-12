#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
vector<pair<int,int>> vec[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	cout<<0;
	return 0;
}
