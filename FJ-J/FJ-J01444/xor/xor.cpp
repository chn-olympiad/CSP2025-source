#include <iostream>
#include <cstdio>
using namespace std;
int n, k, a[500005], need[500005], ans, xs, nl, nr;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) ans++;
		else need[i] = a[i] ^ k;
	}
	for (int i = 1, j; i <= n; i++) {
		if (need[i]) {
			j = i; xs = 0;
			while (need[++j]) {
				xs ^= a[j];
				if (need[i] == xs) {
					if (i > nr) {ans++; nr = j;}
					else if (j < nr) nr = j;
					break;
				}
			}
		}
		else nr = i;
	}
	printf("%d", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
