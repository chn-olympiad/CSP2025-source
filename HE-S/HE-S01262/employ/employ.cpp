#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d", &n, &m);
	string s;
	getline(cin, s);
	int c;
	int p = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c);
		c -= p;
		if (c <= 0) p--;
	}
	long long ans = 1;
	n -= p;
	for (int i = 2; i <= n; i++) ans = (ans * i) % mod;
	printf("%lld", ans);
	return 0;
}
