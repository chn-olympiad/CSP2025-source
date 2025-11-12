#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
int a[N], s[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = a[i] ^ s[i - 1];
	}

	printf("%d", n / 2);
}