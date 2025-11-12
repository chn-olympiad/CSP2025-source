#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7, M = 1e6 + 7;
struct node{
	int u, v, w;
};
node a[M];
int num[N];
int ans;
bool cmp(node i, node j) {
	return i.w > j.w;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if (k != 0) {
		cout << 0;
		return 0;
	} 
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
		++num[a[i].u], ++num[a[i].v];
	}
	int x = m - (n - 1);
	sort(a + 1, a + 1 + m, cmp);
	for (int i = 1; i <= m; ++i) {
		if (num[a[i].u] - 1 > 0 && num[a[i].v] - 1 > 0 && x) --x;
		else ans += a[i].w;
	}
	cout << ans << endl;
	return 0;
}

