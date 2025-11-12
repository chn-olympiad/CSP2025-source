#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
struct edge{
	int u, v, w;
} e[1000100];
bool operator <(edge a, edge b) {
	return a.w < b.w;
}
int f[10100];
int getf(int x) {
	return x == f[x] ? x : f[x] = getf(f[x]);
}
vector<edge> e1;
int c[12], a[12][10100];
ll ans;
void search(int last, ll sum) {
	ll temp = sum;
	for (int i = 1; i <= n + k; i++) f[i] = i;
	sort(e1.begin(), e1.end());
	vector<edge> e2;
	for (auto i : e1) {
		if (getf(i.u) != getf(i.v)) {
			e2.push_back(i);
			temp += i.w;
			f[getf(i.v)] = getf(i.u);
		}
	}
	ans = min(ans, temp);
	e1 = e2;
	if (last == k) return;
	for (int i = last + 1; i <= k; i++) {
		e2 = e1;
		for (int j = 1; j <= n; j++) {
			e1.push_back({n + i, j, a[i][j]});
		}
		search(i, sum + c[i]);
		e1 = e2;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++) f[i] = i;
	for (int i = 1; i <= m; i++) {
		if (getf(e[i].u) != getf(e[i].v)) {
			ans += e[i].w;
			e1.push_back(e[i]);
			f[getf(e[i].v)] = getf(e[i].u);
		}
	}
	search(0, 0);
	cout << ans << '\n';
	return 0;
} 

/*
15:43 Pretests Passed(4)

my luogu UID is 928955
follow me if you see this code

复杂度大概有 3e8，不清楚老爷机的速度。

不过老爷机换成 285K 了，应该能过。
*/