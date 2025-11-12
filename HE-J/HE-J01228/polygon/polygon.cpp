#include <iostream>
#include <stdio.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
int n;
int a[5010];
ll ans = 0;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	bool f = true;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] > 1) f = false;
	}
	if(f) {
		for(ll i = 3; i <= n; i++) {
			ans += ((i * (i - 1) * (i - 2) / 6) % mod);
			ans %= mod;
		}
		printf("%lld", ans % mod);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
