#include<bits/stdc++.h>
#define pii pair < int, int >
using namespace std;

const int N = 1e4 + 20;
int n, m, k, u, v, w, g;
int c[20];
long long ans;
bool f[N];

vector < pii > Map[N];

priority_queue < pii, vector < pii >, greater < pii > > q;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for ( int i = 1; i <= m; i++ ) {
		cin >> u >> v >> w;
		Map[u].push_back({v, w});
		Map[v].push_back({u, w});
	}
	for ( int i = 1; i <= k; i++ ) {
		cin >> c[i];
		for ( int j = 1; j <= n; j++ ) {
			cin >> w;
			Map[n + i].push_back({j, w});
			Map[j].push_back({n + i, w});
		}
	}
	for ( auto &to : Map[1] ) q.push({to.second, to.first});
	f[1] = 1;
	g = 1;
	while ( !q.empty() ) {
		pii x = q.top(); q.pop();
		if ( f[x.second] ) continue;
		f[x.second] = 1;
		ans += x.first;
		g++;
		if ( x.second > n ) g--;
		if ( g == n ) break;
		for ( auto &to : Map[x.second] ) {
			if ( f[to.first] ) continue;
			q.push({to.second, to.first});
		}
	}
	cout << ans;
	return 0;
}
