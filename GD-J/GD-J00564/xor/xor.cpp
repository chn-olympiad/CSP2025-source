#include <stdio.h>
int n, k, a[514514];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	int i, cnt = 0, sum = 0;
	for(i = 1; i <= n; i += 1) {
		scanf("%d", &a[i]);
	}
	for(i = 1; i <= n; i += 1) {
		sum ^= a[i];
		if(sum == k) {
			sum = 0;
			cnt += 1;
		}
	}
	printf("%d", cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
