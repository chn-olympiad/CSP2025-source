#include <bits/stdc++.h>
using namespace std;
const long long N = 100010;
const long long INF = LONG_LONG_MAX - 10ll;
long long T;
long long n;
struct node {
	long long tt[4], maxn;
	long long to;
} p[N];
long long a[N];
long long cnt[4], tot;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		tot = 0;
		scanf("%lld", &n);
		for (long long i = 1; i <= n; i++)
			scanf("%lld%lld%lld", &p[i].tt[1], &p[i].tt[2], &p[i].tt[3]), p[i].maxn = max(p[i].tt[1], max(p[i].tt[2], p[i].tt[3]));
//		for (long long i = 1; i <= n; i++)
//			printf("%lld %lld %lld\n", p[i].tt[1], p[i].tt[2], p[i].tt[3]);
		long long ans = 0;
		for (long long i = 1; i <= n; i++) {
			if (p[i].tt[1] == p[i].maxn) p[i].to = 1;
			else if (p[i].tt[2] == p[i].maxn) p[i].to = 2;
			else p[i].to = 3;
			ans += p[i].maxn;
		}
		for (long long i = 1; i <= n; i++) 
			cnt[p[i].to]++;
		if (cnt[1] <= (n >> 1) && cnt[2] <= (n >> 1) && cnt[3] <= (n >> 1)) {
			printf("%lld\n", ans);
		} else {
			tot = 0;
			long long ch = 0;
			if (cnt[1] > (n >> 1)) ch = 1;
			else if (cnt[2] > (n >> 1)) ch = 2;
			else ch = 3;
			for (long long i = 1; i <= n; i++)
				a[i] = -INF;
			for (long long i = 1; i <= n; i++) {
				if (p[i].to != ch) continue;
				++tot;
				for (long long j = 1; j <= 3; j++) {
					if (j == ch) continue;
					a[tot] = max(a[tot], p[i].tt[j] - p[i].tt[ch]);
					//printf("i : %lld j : %lld ch : %lld %lld\n", i, j, ch, p[i].tt[j] - p[i].tt[ch]);
				}
			}
			sort(a + 1, a + tot + 1, cmp);
			for (long long i = 1; i <= cnt[ch] - (n >> 1); i++)
				ans += a[i];
			printf("%lld\n", ans);
		}
	} 
	return 0;
} 
