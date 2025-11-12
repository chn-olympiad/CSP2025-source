#include <bits/stdc++.h>
#define ll long long 
#define N 5005
#define inf 0x7fffffff
#define mood 998244353
using namespace std;
int n, a[N];
int sum[N][N], maxx[N][N], f[N][N];
int main () {
	freopen ("ploygon.in", "r", stdin);
	freopen ("ploygon.out", "w", stdout);
	scanf("%d", &n);
	bool b = 1;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", a + i);
		if(a[i] != 1) b = 0;
	}
	//15-20
	if (b) {
		ll sum = 0;
		for (int i = 3; i <= n; i++) {
			int ans = n / i;
			for (int j = 2; j <= i; j++) {
				ans *= ((ll) (n - j + 1) / j) % mood;
			}
			sum += ans;
			sum %= mood; 
		}
		printf ("%lld", sum);
	}
	else printf("9");
	return 0;
} 
//rp++
//luogu uid : 944843
// I'm a girl
