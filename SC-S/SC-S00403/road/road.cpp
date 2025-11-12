# include <bits/stdc++.h>
using namespace std;
struct aox{int v,e;};
const int N = 1e4 + 5;
int n,m,k;
int u,v,e;
int c[N];
int a[N][N];
int vis[N];
vector<aox>r[N]; 
int mi = 1e9;
void dfs(int prev,int k){
	if(prev == n){
		mi = min(mi,k);
		return ;
	}
	for(int i = 0;i <= r[prev].size();i++){
		if(vis[r[prev][i].v] == 0){
			vis[r[prev][i].v] = 1;
			dfs(i,k + r[prev][i].e);
		}
	}
} 
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> e;
		r[u].push_back({v,e});
		r[v].push_back({u,e});
	}

	for(int j = 1;j <= k;j++){
		cin >> c[j];
		for(int i = 1;i <= n;i++){
			cin >> a[j][i];
		}
	}

	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= n;j++){
			r[c[j]].push_back({j,a[j][i]});
			r[j].push_back({c[j],a[j][i]});
		}
	}
	
	dfs(1,0);
	cout << mi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}