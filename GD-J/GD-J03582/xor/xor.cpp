#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, k, lim;
int a[N], cnt[0], sum[N], maxn[N], dp[N][N];

void solve1() {
	int num = 0, count = 0;
	if (k == 1) cout << cnt[1] << '\n';
	else {
		for (int i = 1; i <= n; ++i) {
			if (a[i] == (!k)) num++;
			else count += num / 2, num = 0;
		}
		count += num / 2;
		cout << cnt[0] + count << '\n';
	}
}

void solve2() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j >= 1; --j) {
			dp[i][i - j + 1] = maxn[j - 1] + ((sum[i] ^ sum[j - 1]) == k? 1 : 0);
			maxn[i] = max(maxn[i], dp[i][i - j + 1]);
		}
	}
	
	cout << maxn[n] << '\n'; 
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
		cnt[0] += (a[i] == 0);
		cnt[1] += (a[i] == 1);
		lim = max(a[i], lim); 
	}
	
	if (n <= 2000) solve2();
	else if (lim <= 1) solve1();
	else if (lim <= 255) solve2();
	
	return 0;
}
