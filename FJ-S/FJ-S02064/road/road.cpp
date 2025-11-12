#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int n,m,k;

typedef pair<int,int>pr;



int main(int argc,char**argv) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	for(int i=1;i<=m;++i) {
		int u,v,w;
		edge[u].emplace_back(v,w);
		edge[v].emplace_back(u,w);
	}
	
	for(int i=1;i<=k;++i) {
		cin>>p[i+n];
		for(int j=1;j<=n;++j) {
			int w;
			edge[i+n].emplace_back(j,w);
			edge[j].emplace_back(i+n,w);
		}
	}
	
	return 0;
}
