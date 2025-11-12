#include <bits/stdc++.h>
using namespace std;
const int N=1e6 + 100;

struct node{
	int u, v, w;
} a[N];
bool cmp(node a, node b) {
	return a.w < b.w;
}
bool vis[N];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k, ans = 0;
	cin >> n >> m >> k;
	int c[N], vi[N];
	for (int i = 1; i <= n; i++) {
		cin >> a[i].u>>a[i].v>>a[i].w;
		ans += a[i].w;
	}
	sort (a + 1, a + 1 +n, cmp);
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> vi[j];
		}
	}
	cout << ans;
	return 0;
}
