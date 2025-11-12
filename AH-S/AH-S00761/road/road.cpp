#include<algorithm>
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const ll N = 1e4 + 1;
struct node {
	ll v, w;
};
ll n, m, k, ans, c[N], fee[11][N];
ll U[N], V[N], W[N];
vector<node> g[N];
void Subtask1() {
	sort(W + 1, W + m + 1);
	ans = 0;
	for(int i = 1; i < n; ++ i) ans += W[i];
	cout << ans;
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i) {
		cin >> U[i] >> V[i] >> W[i];
		g[U[i]].push_back((node) {V[i], W[i]});
		g[V[i]].push_back((node) {U[i], W[i]});
	}
	for(int i = 1; i <= k; ++ i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++ j) cin >> fee[i][j];
	}
	if(k == 0) Subtask1();
	return 0;
}
