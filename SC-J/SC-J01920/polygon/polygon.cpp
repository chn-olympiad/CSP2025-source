#include <bits/stdc++.h>
using namespace std;

long long n, a[5010], c[30], ans;
const int P = 998244353;

void dfs (int x, int y){
	if (x == n + 1){
		if (y < 3)
			return;
		long long v = 0, u = 0;
		for (int i = 1; i <= n; i++){
			if (c[i]){
				v = max (v, a[i]);
				u += a[i];
			}
		}
		if (v * 2 < u){
			ans++;
		}
		ans %= P;
		return;
	}
	c[x] = 1;
	dfs (x + 1, y + 1);
	c[x] = 0;
	dfs (x + 1, y);
}

int main (){
//	freopen ("polygon.in", "r", stdin);
//	freopen ("polygon.out", "w", stdout);
	scanf ("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	if (n <= 20){
		dfs (1, 0);
		printf ("%lld", ans);
		return 0;
	}
	if (a[n] == 1){
		ans = 1;
		for (int i = 1; i <= n; i++){
			ans *= 2;
			ans %= P;
		}
		ans = ans - n - n * (n - 1) / 2 - 1;
		printf ("%lld", ans);
		return 0; 
	}
	dfs (1, 0);
	printf ("%lld", ans);
	return 0;
}