#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10,M = 1e6+10;
int n,m,k;
long long ans;
vector <int> G[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].push_back(v);
		G[v].push_back(u);
		ans += w;
	}
	cout << ans;
	return 0;
}
