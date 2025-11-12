#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn][3];
int cnt[3], sum[3];
int d[maxn];
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int tid; cin >> tid;
	while (tid --) {
		cnt[0] = cnt[1] = cnt[2] = sum[0] = sum[1] = sum[2] = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			int mx = max(max(a[i][0], a[i][1]), a[i][2]);
			if (mx == a[i][0]) cnt[0] ++, sum[0] += mx;
			else if (mx == a[i][1]) cnt[1] ++, sum[1] += mx;
			else if (mx == a[i][2]) cnt[2] ++, sum[2] += mx;
		} int pos = -1;
		if (cnt[0] > n / 2) pos = 0;
		else if (cnt[1] > n / 2) pos = 1;
		else if (cnt[2] > n / 2) pos = 2;
		if (pos == -1) {
			cout << sum[0] + sum[1] + sum[2] << '\n';
		} else {
			int Ans = sum[0] + sum[1] + sum[2];
			int N = cnt[pos] - (n / 2), mor = 0, tot = 0;
			for (int i = 1; i <= n; i ++) {
				int M = a[i][pos];
				int L = (pos + 1) % 3, R = (pos + 2) % 3;
				if ((M > a[i][L] || (M == a[i][L] && pos < L)) && (M > a[i][R] || (pos < R && M == a[i][R]))) {
					tot ++;
					int sec = max(a[i][L], a[i][R]);
					d[tot] = M - sec;
				}
			}
			sort(d + 1, d + cnt[pos] + 1);
			for (int i = 1; i <= N; i ++) {
				mor += d[i];
			}
			Ans -= mor;
			cout << Ans << '\n';
		}
	}
	return 0;
}
