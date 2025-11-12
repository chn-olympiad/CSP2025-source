#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, cnt = 0;
	scanf("%d%d", &n, &k);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1, sum = -1; i <= n; i++) {
		if (a[i] == k) {
			cnt++, sum = -1;
			continue;
		}
		if (sum == -1) sum = a[i];
		else sum ^= a[i];
		if (sum == k) cnt++, sum = -1;
	}
	printf("%d", cnt);
	return 0;
}
