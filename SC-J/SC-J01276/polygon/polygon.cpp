#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 5e3 + 5;
const int mode = 998244353;

int n, ans;
int len[maxn];
int sum[maxn];

signed main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	scanf("%lld", &n);

	if (n == 3) {
		for (int i = 1; i <= n; i++) scanf("%lld", &len[i]);
		int cnt = len[1] + len[2] + len[3];
		int maxlen = max(len[1], max(len[2], len[3]));
		if (2 * maxlen < cnt) printf("1");
		else printf("0");
		return 0;
	}

	for (int i = 1; i <= n; i++) scanf("%lld", &len[i]);

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + i;
	}

	//i边形
	for (int i = 3; i <= n; i++) {
		int temp = n - i + 1;
		int temp_ans = 0;
		for (int i = 1; i <= temp; i++) temp_ans += sum[i];
		temp_ans %= mode;
		ans += temp_ans;
		ans %= mode;
	}

	printf("%lld", ans);

	return 0;
}