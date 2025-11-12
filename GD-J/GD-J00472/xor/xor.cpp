#include <bits/stdc++.h>
using namespace std;
long long n, k, c1, c0, arr[500010];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1) c1++;
		if (arr[i] == 0) c0++;
	}
	if (c1 == n) printf("%d", n);
	else if (c1 + c0 == n) printf("2");
	fclose(stdin);
	fclose(stdout);
	return 0;
}