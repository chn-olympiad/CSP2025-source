#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, s[N], c[N], p[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%1d", &s[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	for (int i = 1; i <= n; ++i) p[i] = i;
	int ans = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) 
			cnt += !s[i] || (cnt >= c[p[i]]);
		ans += n >= m + cnt;
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans % mod << '\n';
	return 0;
}
/*
g++ employ.cpp -o employ -std=c++14 -O2 -static
*/