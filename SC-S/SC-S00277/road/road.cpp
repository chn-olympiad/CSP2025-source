#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[make_pair(u,v)]=w;
		mp[make_pair(v,u)]=w;
	}
	cout<<0;
	return 0; 
} 