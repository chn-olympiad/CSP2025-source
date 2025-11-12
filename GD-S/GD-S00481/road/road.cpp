#include <bits/stdc++.h>
#define int long long
#define N 10005
#define K 15
#define INF 1e18
using namespace std;

int n,m,k;
int c[K],a[K][N];
int dis[N][N];
int ans;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	cin >> n >> m >> k;for (int i=1;i<=m;++i){
 		int u,v,w; cin >> u >> v >> w;
 		if (dis[u][v] == 0){
 			dis[u][v] = w;
 			dis[v][u] = w;
		 }
		 else dis[u][v] = dis[v][u] = min(dis[u][v],w);
	}
	
	int maxn = 0;
	for (int i=1;i<=k;++i){
		cin >> c[i];
		maxn = max(c[i],maxn);
		for (int j=1;j<=n;++j){
			cin >> a[i][j];
		}
	}
	
	ans = INF; 
	
	if (maxn == 0){
		for (int u=1;u<=n;++u){
			int sum = 0;
			for (int v=1;v<=n;++v){
				if (u == v) continue;
				int cnt = (dis[u][v] ? dis[u][v] : INF);
				for (int i=1;i<=k;++i) cnt = min(cnt,a[i][u]+a[i][v]);
				sum += cnt;
			}
			ans = min(ans,sum);
		}
	}
	cout << ans;
	
 	
 	
 	
 	return 0;
 }
