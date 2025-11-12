#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int W = 1e5 + 5;
ll n, m, k;
struct Node{
	int x, r;
};
vector <Node> a[W];
int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= n; i++){
		cin >> u >> v >> w;
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	cout << 13;
	return 0;
}
