#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == k) {
			ans++;
			a[i] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) continue;
		for (int j = i; j < n; j++) {
			int s = a[j];
			for (int l = 1; l + j < n; l++) {
				s ^= a[j + l];
				if (s == k) {
					ans++;
					i = j + l;
					j += l;
					break;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
