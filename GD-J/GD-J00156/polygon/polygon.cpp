#include <bits/stdc++.h>
#define int long long
using namespace std;

int s[5010];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i ++) {
		int tmp = i;
		int cnt = 1, maxn = LLONG_MIN;
		vector<int> v;
		while (tmp > 0) {
			int now = tmp % 2;
			if (now == 1) {
				v.push_back(s[cnt]);
				maxn = max(maxn, s[cnt]);
			}
			cnt ++;
			tmp /= 2;
		}
		if (v.size() < 3) continue;
		int sum = 0;
		for (auto i : v) sum += i;
		if (sum > 2 * maxn) ans ++;
	}
	
	cout << ans << endl;
	
	return 0;
}
