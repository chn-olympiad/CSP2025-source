#include<bits/stdc++.h>
using namespace std;
#define nmax 500007
#define int long long
int n, k;
int a[nmax];
int dp[nmax];

bool checkA() {
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1) {
			return 0;
		}
	}

	return 1;
}

bool close(int x, int y, int z) { // y相比于x更靠近z?
	int xz = abs(z - x);
	int yz = abs(z - y);
	return yz < xz;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	bool isA = checkA();

	if (k == 0 && isA) {
		cout << (n >> 1);
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			dp[i] = k;
		} else {
			if (close(dp[i], dp[i - 1]^a[i], k) && dp[i - 1] != k) {
				dp[i] = dp[i - 1] ^ a[i];
			} else {
				dp[i] = a[i];
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (dp[i] == k) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}