#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
const int M = 4e6 + 5;
const int K = 4e1 + 5;
long long n, m, k, b[N], c[K][N], fa[N];
array<long long, 3> a[M];
long long ans;
bool cmp(array<long long, 3> x, array<long long, 3> y) {
	return x[2] < y[2];
}
long long find(long long x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	for (long long i = 1; i <= m; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (long long i = 1; i <= n; ++i) fa[i] = i;
	for (long long i = 1; i <= k; ++i) {
		cin >> b[i];
		int num = 0;
		for (long long j = 1; j <= n; ++j) {
			cin >> c[i][j];
			if (b[i] == 0 && c[i][j] == 0) num = j;
		}
		for (long long j = 1; j <= n; ++j) {
			if (j != num) {
				++m;
				a[m][0] = num;
				a[m][1] = j;
				a[m][2] = c[i][j];
			}
		}
	}
	sort(a + 1, a + m + 1, cmp);
	for (long long i = 1; i <= m; ++i) {
		long long x = find(a[i][0]);
		long long y = find(a[i][1]);
		if (x == y) continue;
		fa[x] = y;
		ans += a[i][2];
	}
	cout << ans;
	return 0;
}
