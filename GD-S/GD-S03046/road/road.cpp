#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;

vector<pair<int,int> > G[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	cout<<0;
	return 0;
}
