#include<bits/stdc++.h>
using namespace std;

int n, k, a[500010], ans;

int main () {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int t = a[i];
		if (t == k) ans++;
		for (int j = i + 1; j <= n; j++) {
			t ^= a[j];
			if (t == k) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
