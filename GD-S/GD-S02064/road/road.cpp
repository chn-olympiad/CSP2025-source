#include<bits/stdc++.h>
using namespace std;
int const N=1e4+7;
vector<pair<int,int> > a;
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		a.push(u,v);
	}
	while(k--){
		int x;
		for(int i=1;i<=n;i++) cin>>x;
	}
	
	return 0;
}
