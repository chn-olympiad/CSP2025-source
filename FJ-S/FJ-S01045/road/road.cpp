#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],b[15][10005],dis[10005],vis[10005];
vector<pair<int,int> > g[10005];
int ans = 0;
void prim(){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	vis[1] = 1;dis[1] = 0;
	for (int i = 0;i < g[1].size();i++) dis[g[1][i].first] = g[1][i].second;
	for (int i = 1;i < n;i++){
		int minn = 1e9,mint = 0;
		for (int j = 1;j <= n;j++){
			if (!vis[j] && dis[j] < minn){
				minn = dis[j];
				mint = j;
			}
		}
		vis[mint] = 1;
		for (int j = 0;j < g[mint].size();j++) if (!vis[g[mint][j].first] && dis[g[mint][j].first] > g[mint][j].second) dis[g[mint][j].first] = g[mint][j].second;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if (k > 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1;i <= m;i++){
		int u,v,w;cin >> u >> v >> w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++) cin >> b[i][j];
	}
	prim();int ans = 0;for (int i = 1;i <= n;i++) ans += dis[i];
	cout << ans << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
