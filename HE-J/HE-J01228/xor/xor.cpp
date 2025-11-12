#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 5e5 + 10;
struct node {
	int x;
	bool isused;
}a[N];
int k, n;
int sum[N];
inline bool check(int bigen, int edn) {
	for(register int i = bigen; i <= edn; i++) {
		if(a[i].isused) return 0;
	}
	return 1;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i].x);
		sum[i] = sum[i - 1] ^ a[i].x; // a_l ^ a_l+1 ^ a_l+2 ^ ... ^ a_r = s[r] ^ a[l - 1]
	}
	int ans = 0;
	for(int len = 1; len <= n; len++) {
		for(int i = 1; i <= n - len + 1; i++) {
			if(check(i, i + len - 1) && (sum[i + len - 1] ^ sum[i - 1]) == k) {
				a[i + len - 1].isused = 1;
				a[i].isused = 1;
				ans++;
//				printf("%d  %d %d\n--%d %d  %d\n", len, i, i + len - 1, sum[i - 1], sum[i + len - 1], sum[i + len - 1] ^ sum[i - 1]);
			}
		}
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
