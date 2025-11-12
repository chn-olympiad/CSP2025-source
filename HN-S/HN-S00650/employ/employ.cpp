#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 201000;
const ll mod = 998244353;

int n, m, a[N];
char s[N];
ll ans;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ans = (ans * (!a[i] ? 1 : a[i])) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

