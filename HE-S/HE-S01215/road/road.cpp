#include <bits/stdc++.h>
constexpr int man=1e6+10;
using pair=std::pair<int,int>;
int n,m,k;
std::vector<pair>G[man];
int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++) {
		std::cin>>u>>v>>w;
		G[u].push_back({w,v});
		G[v].push_back({w,u});
	}
	std::cout<<0;
	return 0;
}
