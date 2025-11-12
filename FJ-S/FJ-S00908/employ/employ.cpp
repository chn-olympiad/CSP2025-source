/* CSP2025 RP++
yuji 8 */
#include <bits/stdc++.h>
using namespace std;
int n, m, c[510], p[510]; char str[510];
int main() {
	freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
	scanf("%d %d %s", &n, &m, str + 1);
	for (int i = 1; i <= n; ++i) scanf("%d", c + i), p[i] = i;
	int ans = 0;
	do {
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (sum >= c[p[i]]) { ++sum; continue; }
			sum += (str[i] ^ 49);
		}
		if (n - sum >= m) ++ans;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans<<endl;
}
