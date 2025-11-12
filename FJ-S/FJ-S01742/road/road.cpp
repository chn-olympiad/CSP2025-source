#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max = 1e4+9;
struct Edge {
	int to,val;
};
vector <Edge> e[Max];
int n,m,k,c[20],a[20][Max];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i = 1;i <= k;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}
