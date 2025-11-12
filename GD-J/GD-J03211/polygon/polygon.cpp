#include <cstdio>
#include <algorithm>
#define N 5005
#define MOD 998244353
//#define LOCAL

using namespace std;

int a[N] = {}, ans = 0, n;

int main() {
	#ifndef LOCAL
		freopen("polygon.in", "r", stdin);
		freopen("polygon.out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		
	for (int S = 1; S < 1 << n; S++) {
		if (__builtin_popcount(S) < 3) continue;
		
		int sum = 0, maxl = -1;
		for (int i = 0; i < n; i++)
			if (S & (1 << i)) {
				sum += a[i + 1];
				maxl = max(maxl, a[i + 1]);
			}
			
		if (sum > 2 * maxl) ans = (ans + 1) % MOD; 
	}
	
	printf("%d", ans);
	
	#ifndef LOCAL
		fclose(stdin);
		fclose(stdout);
	#endif
	
	return 0;
}
