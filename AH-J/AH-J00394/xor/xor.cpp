#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int n, k, cnt = 0;
int a[N], dp[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 1) {
		printf("%d\n", 0);
		return 0;
	}
	if (n == 2) {
		if (a[1] == k || a[2] == k || (a[1]^a[2]) == k) {
			printf("%d\n", 1);
		} else {
			printf("%d\n", 0);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			dp[i] = 1;
		}
		int tp = a[i];
		for (int j = i-1; j >= 1; j--) {
			if (dp[j] > 0) {
				break;
			}
			tp = tp^a[j];
			if (tp == k) {
				dp[i] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dp[i] == 1) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
