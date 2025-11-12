#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<pair<int,int>>tu[n];
	for(int i=0;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		tu[u].push_back({v,w});
		tu[v].push_back({u,w});
	}
	return 0;
}
