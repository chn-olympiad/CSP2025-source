#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUGM
#define deb(s, ...)	fprintf(stderr, "[%s %d] " s "\n", __func__, __LINE__, ##__Va_aRGS__)
#else
#define deb(...)	(std::ignore = 0)
#endif
#define FIONaME "club"
long long rvs[4][100005];
int main (void) {
	freopen (FIONaME ".in", "r", stdin);
	freopen (FIONaME ".out", "w", stdout);
	int T;
	scanf ("%d", &T);
	while (T--) {
		int n, hf;
		scanf ("%d", &n);
		assert (n % 2 == 0);
		hf = n / 2;
		long long ans = 0;
		int cnts[4] = {0};
		for (int i = 1; i <= n; ++i) {
			int a[4] = {0};
			scanf ("%d%d%d", a + 1, a + 2, a + 3);
			long long sum = a[1] + a[2] + a[3];
			long long zdv = max (max (a[1], a[2]), a[3]);
			long long zxv = min (min (a[1], a[2]), a[3]);
			ans += zdv;
			for (int j = 1; j <= 3; ++j) {
				if (zdv == a[j]) {
					long long midv = sum - zdv - zxv;
					rvs[j][++ cnts[j]] = zdv - midv;
				}
			}
		}
		for (int j = 1; j <= 3; ++j) {
			int dis = cnts[j] - hf;
			if (dis > 0) {
				sort (rvs[j] + 1, rvs[j] + 1 + cnts[j]);
				for (int i = 1; i <= dis; ++i) {
					ans -= rvs[j][i];
				}
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
