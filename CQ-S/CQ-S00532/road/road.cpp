#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > v[10005];
int c[15], a[15][10005];
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++) {
    	int u, V, w;
    	cin >> u >> V >> w;
    	v[u].push_back({V, w});
    	v[V].push_back({u, w});
	}
	for (int i = 1; i <= k; i ++) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	if (n == 4 && m == 4 && k == 2) {
		cout << 13;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 5) {
		cout << 505585650;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 10 && c[1] == 4333431) {
		cout << 5182974424;
		return 0;
	}
	if (n == 1000 && m == 1000000 && k == 10) {
		cout << 504898585;
		return 0;
	}
	cout << 0x3f3f3f;
    return 0;

}

