#include <bits/stdc++.h>
using namespace std;
int n, m, k, c[1000005], b[15][10005], f[1000005];
struct st{
	int from, to, w;
}a[1000005];
bool cmp(st x, st y) {
	return x.w < y.w;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].from >> a[i].to >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
		}
	}
	sort (a + 1, a + m + 1, cmp);
	long long ans = 0, minx;
	for (int i = 1; i <= m; i++) {
		minx = a[i].w;
		for (int j = 1; j <= k; j++) {
			if (j == a[i].from) {
				if (f[i]) {
					if (minx > b[j][a[i].to]) {
						minx = b[j][a[i].to];
					}
				} else {
					if (minx > c[i] + b[j][a[i].to]) {
						minx = c[i] + b[j][a[i].to];
					}
					f[i] = 1;
				}
			}
		}
		ans += minx;
	}
	cout << ans;
	return 0;
}
