#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int mod = 998244353;
int a[N], b[N];
int dp[N];

bool cmp(int x, int y) {
	return x > y;
}

long long mul(int n) {
	if (n <= 1) return 1;
	return (1LL * n * mul(n - 1)) % mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		a[i + 1] = s[i] - '0';
		dp[i + 1] = dp[i];
		if (a[i + 1] == 0) dp[i + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	long long tot = mul(n);
	long long ms = 1;
	sort(b + 1, b + n + 1, cmp);
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			int cnt = -1;
			for (int j = 1; j <= n; j++) if (dp[j] == b[i]) {
				cnt = j;
				break;
			}
			if (cnt != -1) ms = (1LL * ms * mul(n - cnt + 1)) % mod;
			else ms = 0;
		}
		printf("%d\n", (tot - ms + mod) % mod);
	} else {
		printf("0");
	}
	return 0;
} 
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
//qwq qwq qwq
