#include<bits/stdc++.h>
using namespace std;
const int MOD = 908244353; 
int n, a[5010], ai, Max = -1;
long long ans;
long long SUM(int num, int i) {
	if(i = 1) {
		return num % MOD;
	} 
	return (num * SUM(num - 1, i - 1)) % MOD;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	if(n == 3) {
		int sum= 0;
		for(int i = 0; i <= 2; i ++) {
			scanf("%d", &a[i]);
			sum += a[i];
			if(a[i] > Max) {
				Max = a[i];
			}
		}
		if(sum > 2 * Max) {
			printf("1");
			return 0;
		} else {
			printf("0");
			return 0;
		}
	}
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &ai);
		a[ai] ++;
	}
	if(a[1] = n) {
		for(int i = 3; i <= n; i ++) {
			ans += (SUM(n, i) / 2 / n) % MOD;
		}
		printf("%lld", ans);
		return 0;
	}
	printf("0");
	return 0;
}
