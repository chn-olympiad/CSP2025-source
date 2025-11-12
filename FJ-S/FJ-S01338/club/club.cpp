#include<bits/stdc++.h>
using namespace std;
long long n, a[1000006][4], ans, cnt[4], s[1000006], b[1000006], cntt, T;
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
//			cin >> a[i][1] >> a[i][2] >> a[i][3];
			scanf("%lld %lld %lld", &a[i][1], &a[i][2], &a[i][3]);
		}
		for (int i = 1; i <= n; i++) {
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				cnt[1]++;
				b[i] = 1;
				ans += a[i][1];
			} else {
				if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
					cnt[2]++;
					b[i] = 2;
					ans += a[i][2];
				} else {
					cnt[3]++;
					b[i] = 3;
					ans += a[i][3];
				}
			}
		}
		if (max(cnt[1], max(cnt[2], cnt[3])) <= n / 2) {
			cout << ans << "\n";
		} else {
			cntt = 0;
			if (cnt[1] >= cnt[2] && cnt[1] >= cnt[3]) {
				for (int i = 1; i <= n; i++) {
					if (b[i] == 1) {
						s[++cntt] = a[i][1] - max(a[i][2], a[i][3]);
					}
				}
			} else {
				if (cnt[2] >= cnt[1] && cnt[2] >= cnt[3]) {
					for (int i = 1; i <= n; i++) {
						if (b[i] == 2) {
							s[++cntt] = a[i][2] - max(a[i][1], a[i][3]);
						}
					}

				} else {
					for (int i = 1; i <= n; i++) {
						if (b[i] == 3) {
							s[++cntt] = a[i][3] - max(a[i][2], a[i][1]);
						}
					}
				}
			}
			sort(s + 1, s + 1 + cntt);
			for (int i = cntt; i > n / 2; i--) ans-= s[cntt - i + 1];
			cout << ans << "\n";
		}
		ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
	}

}

