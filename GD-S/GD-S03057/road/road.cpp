#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 10010
#define M 1000010
#define K 20
struct node {
	int u, w, v;
}e[N];

int n, m, x;
int c[K];
int a[K][N];
bool cmp(node x, node y) {
	return x.v < y.v;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> x;
	for(int i = 1;i <= m;i++) {
		int u, w, v;
		cin >> u >> w >> v;
		e[i] = {u, w, v};
	}
	for(int i = 1;i <= x;i++) {
		cin >> c[i];
		for(int j = 1;j <= n;j++) {
			cin >> a[i][j];
		}
	}
	sort(e + 1, e + n + 1, cmp);
	int sum = 0;
	for(int i = 1;i < n;i++) {
		sum += e[i].v;
	}
	cout << sum << "\n";
	return 0;
} 
