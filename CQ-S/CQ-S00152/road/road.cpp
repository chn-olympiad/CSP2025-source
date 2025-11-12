#include<bits/stdc++.h>
#define ll long long
#define fast_running ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
const ll INF = 0x3f3f3f3f3f3f3f;
#define min(x, y) (x < y ? x : y)
ll n, m, k, ans, cnt;
int dist[N];
ll cj[12][N];
bool used[12];
struct edge{
	ll u, v, w;
}e[M << 1];
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
inline int findw(int x) {
	if(dist[x] == x) return x;
	return dist[x] = findw(dist[x]);
}
int main() {
	fast_running;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> cj[i][0];
		for (int j = 1; j <= n; j++) cin >> cj[i][j];
	}
	for (int i = 1; i <= n; i++) dist[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int f1 = findw(e[i].u), f2 = findw(e[i].v);
		if (f1 != f2) {
			dist[f1] = f2;
			ans += e[i].w;
			++cnt;
			if (cnt == n - 1) break;
		}
	}
	cout << ans;
	return 0;
}
/*

I want to get more points, but I can`t!
Whuu....

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

504898585
318604383
*/
