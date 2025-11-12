#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	vector<int> wt[2];
}	a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w1;
		cin>>u>>v>>w1;
		a[u].wt[0].push_back(v);
		a[u].wt[1].push_back(w1);
		a[v].wt[0].push_back(u);
	}
	cout<<a[1].wt[0][0]<<0;
	return 0;
}

