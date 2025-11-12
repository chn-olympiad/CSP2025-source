#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;

int n, m;
int s[100000];
int c[100000];
int a[100000];
string ss;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%lld%lld", &n, &m);
	int pd = 0;
	cin >> ss;
	for (int i = 1; i <= n; i++)
		s[i] = ss[i - 1] - '0', pd += s[i];
	for (int i = 1; i <= n; i++)
		scanf("%lld", &c[i]), a[i] = i;
	int ans = 0;
	do {
		int sum = 0, did = 0;
		for (int i = 1; i <= n; i++) {
			if (c[a[i]] <= did || s[i] == 0) did++;
			else sum++;
		}
		if (sum >= m) ans++;
	} while (next_permutation(a + 1, a + 1 + n));
	printf("%lld\n", ans % mod);
//	if (pd == n) {
//		int ans = 1;
//		for (int i = 1; i <= n; i++)
//			ans = ans * i % mod;
//		printf("%lld\n", ans);
//		return 0;
//	}


	return 0;
}
