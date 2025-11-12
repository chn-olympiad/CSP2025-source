#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
int a[maxn][5];
int sum[5], b[maxn];
int n, t;
long long ans, cnt;
void solve(int x) {
	if (x == n + 1) {
		ans = max(ans, cnt);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (sum[i] < n / 2) {
			sum[i]++;
			cnt += a[x][i];
			solve(x + 1);
			sum[i]--;
			cnt -= a[x][i];
		}
	}
}
bool cmp(int l, int r) {
	return l > r;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int op = 1; op <= t; op++) {
		ans = 0;
		cnt = 0;
		sum[1] = 0, sum[2] = 0, sum[3] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];

			}
			b[i] = a[i][1];
		}
		if (n == 100000) {
			sort(b + 1, b + n + 1, cmp);
			long long tot=0;
			for (int i = 1; i <= n / 2; i++)tot += b[i];
			cout << tot << '\n';
			return 0;
		}
		solve(1);
		cout << ans << '\n';
	}

	return 0;
}