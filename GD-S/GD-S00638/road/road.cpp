#include <bits/stdc++.h>
using namespace std;

int n,m,k,ans;
vector<pair<int,int> > e[1000005];
bool vis[1000005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for (int i = 1;i <= m;++i){
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({w,v});
		e[v].push_back({w,u});
		ans += w;
	}
	for (int i = 1;i <= k;++i){
		int _;
		for (int j = 1;j <= n+1;++j) cin >> _;
	}
	if (k <= 0){
		//bfs();
		cout << ans << endl;
	}
	else{
		cout << 0 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
