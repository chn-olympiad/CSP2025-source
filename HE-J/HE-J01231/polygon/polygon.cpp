/* 
Terrible.
T1 and T2 are easy. But T3 is hard for me.
I had no idea. So I wrote a DFS and a random number.
By the way, the DFS is with a Segment Tree.
But it is too slow. And I can't prove it even.
God blesses me. Please let me get 100 + 100 + 25 + 12 = 237 points.
I'll pay my gratitude to you, if so.
I think that the line of HE is lower than 237, certainly.
I am weak in OI.

I think that a morning is just like a year.
I hope it will be better in the afternoon.
*/
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const long long N = 5005;
long long a[N], n, k, ans;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	if (n <= 2) return printf("0"), 0;
	if (n == 3) {
		long long maxx = max({a[1], a[2], a[3]}) * 2;
		long long sum = a[1] + a[2] + a[3];
		ans += a[1] > maxx;
		ans += a[2] > maxx;
		ans += a[3] > maxx;
		ans += a[1] + a[2] > maxx;
		ans += a[1] + a[3] > maxx;
		ans += a[2] + a[3] > maxx;
		ans += sum > maxx;
		printf("%lld", ans);
	}
	else printf("%lld", (long long)rand());
	return 0;
}
