#include<iostream>
#include<algorithm>
using namespace std;
int n, k, a[500005], sum[500005];
int chg[22];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int Max = 1;
	while (Max <= k) {
		Max *= 2;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int l = 1, r = 0, s = 0, ans = 0;
	while (r < n) {
		s ^= a[++r];
		if (s == k) {
			l = r + 1;
			++ans;
			s = 0;
		} else {
			for (int i = l; i < r; i++) {
				if ((s ^ (sum[i] ^ sum[l - 1])) == k) {
					l = r + 1;
					++ans;
					s = 0;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
//TLE 75~100pts
//啥玩意这是，感觉t4更简单
