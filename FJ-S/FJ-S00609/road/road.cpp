#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int vis[N + 10]; 
int dk[20];
int n,m,k;
long long sum;
struct s{
	int v,w;
};
vector <s> a[N + 20];
void solve() {
	int t = 1;
	int x = n-1;
	while (x) {
		cout << t << endl;
		vis[t] = 1;
		int mi = 2147483647,id;
		for(int i = 0; i < a[t].size(); i++) {
			if(vis[a[t][i].v]) continue;
			if (a[t][i].v <= n) {
				if (a[t][i].w < mi) {
					mi = a[t][i].w;
					id = i;
				}
			} else {
				if (a[t][i].w + dk[a[t][i].v] < mi) {
					mi = a[t][i].w;
					id = i;
				}
			}
		}
		int ts = a[t][id].v;
		sum += mi;
		if (ts > n) {
			sum += dk[ts];
			dk[ts]=0;
		}
		if (ts <= n) x--;
		t = ts;
	}
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int v,u,w;
		cin >> u >> v >> w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	for (int i = m + 1; i <= m + k; i++) {
		cin >> dk[i];
		for (int j = 1; j <= n; j++) {
			int w;
			cin >> w;
			a[i].push_back({j,w});
			a[j].push_back({i,w});
		}
	}
	solve();
	cout << sum++ << endl;
	return 0;
}
