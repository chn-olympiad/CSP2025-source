#include<bits/stdc++.h>
using namespace std;
long long N=2e6+7;
long long n,m;
vector<vector<pair<int,int> > > d;
struct node{
	bool operator < (const &node o) const{
		return dist>o.dist;
	}
};


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		d[u].push_back({v,w});
		d[v].push_back({u,w});
		
	}
	for(int i=1;i<=m;i++){
		cout<<d[i];
	}

	return 0;
}
