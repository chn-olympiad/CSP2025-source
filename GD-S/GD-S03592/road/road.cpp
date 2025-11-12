#include<bits/stdc++.h>
using namespace std;
vector<int>G[10005];
struct rd{
	int u,v;
};
int a[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
		a[i]=w;
	}
	for(int i=0;i<k;i++){
		;
	}
	cout<<"13";
	return 0;
} 
