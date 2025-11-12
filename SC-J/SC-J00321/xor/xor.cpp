#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, k, a[N], sum[N];
bool vis[N];
struct node {
	int l, r;
}d[N];
bool cmp (node x, node y) {
	if ((x.r - x.l) == (y.r - y.l)) {
		return x.r < y.r;
	}
	return (x.r - x.l) < (y.r - y.l); 
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] ^ a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (abs(sum[i] - sum[j]) == k) {
				cnt++;
				d[cnt].l = i + 1, d[cnt].r = j;
			}
		}
	}
	sort(d + 1, d + cnt + 1, cmp);
//	for (int i = 1; i <= cnt; i++) {
//		cout << d[i].l << " " << d[i].r << '\n';
//	}
	long long ans = 0;
	for (int i = 1; i <= cnt; i++) {
		bool flag = 1;
		for (int j = d[i].l; j <= d[i].r; j++) {
			if (vis[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			ans++;
			for (int j = d[i].l; j <= d[i].r; j++) {
				vis[j] = 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
} 