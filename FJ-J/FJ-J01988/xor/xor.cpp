#include<cstdio>
int n, k, a[500001], num = 0, lr = -1;
int val(int l, int r) {
	if (l == r) return a[l];
	else return a[r] ^ val(l, r - 1);
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = lr + 1; j <= i; ++j) {
			if (val(j, i) == k) {
				++num, lr = i;
				break;
			}
		}
	}
	printf("%d", num);
	fclose(stdin); fclose(stdout);
	return 0;
}
