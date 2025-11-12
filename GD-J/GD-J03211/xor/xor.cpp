#include <cstdio>
#include <algorithm>
#define N (int)(5e5 + 10)
#define int long long
//#define LOCAL

int a[N] = {};

signed main() {
	#ifndef LOCAL
		freopen("xor.in", "r", stdin);
		freopen("xor.out", "w", stdout);
	#endif
	
	int n, k, ans = -1;
	scanf("%lld%lld", &n, &k);
	
	for (int i = 1; i <= n; i++) 
		scanf("%lld", a + i);
		
	for (int si = 1; si <= n; si++) {
		int cnt = 0;
		for (int i = si; i <= n; i++) {
			int j = i, sum = a[i];
			while (j <= n && sum != k) sum ^= a[++j];
			if (j <= n) {
				i = j;
				cnt++;
			}
		}
		ans = std::max(ans, cnt);
	}
	
	printf("%lld", ans);
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	
	return 0;
}
