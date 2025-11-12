#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int l = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		int j = i, x = 0;
		while (j > l) {
			x ^= a[j];
			if (x == k) {
				l = i;
				sum++;
				break;
			}
			j--;
		}
	}
	printf("%d\n", sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
