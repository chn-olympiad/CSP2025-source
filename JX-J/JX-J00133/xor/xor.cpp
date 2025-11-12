#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500010];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	int cnt1 = 0, cnt0 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			cnt1++;
		}else if (a[i] == 0) {
			cnt0++;
		}
	}
	if (k == 0) {
		printf("%d\n", cnt1 / 2 + cnt0);
	}else if (k == 1) {
		printf("%d\n", cnt1);
	}else {
		
	}
	return 0;
}
