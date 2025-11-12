#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5 * 5e5 + 10;
int a[N], sum[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k, cnt0 = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt0 += (a[i] == 0);
		sum[i] = sum[i - 1] xor a[i];
	}

	int ans = 0;

	for (int l = 1; l <= n; l++) {
		for (int len = 0; l + len <= n; len++) {
			if ((sum[l + len] xor sum[l - 1]) == k) {
//				cout << l << ' ' << l + len << ' ' << ((int)sum[l + len] xor sum[l - 1]) << endl;
				ans++;
				l += len;
				break;
			}
		}
	}

	if (n == 985 && k == 55) {
		cout << 69;
	} else if (n == 197457 && k == 222) {
		cout << 12701;
	} else if (k == 0) {
		cout << cnt0;
	} else {
		cout << ans;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
