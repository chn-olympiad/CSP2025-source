#include <bits/stdc++.h>
using namespace std;

char s[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	// 20pts
	int n, m, tmp;
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i=0; i<n; i++) {
		scanf("%d", &tmp);
	}
	long long ans = 1;
	for (int i=n; i>=1; i--) {
		ans = (ans * i) % 998244353;
	}
	printf("%d", ans);
	return 0;
}
