#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll n, k, cnt1, cnt0, a[500005];
bool used[500005];

void specilA() {
	cout << n / 2 << "\n";
}

void specilB() {
	ll left = 1, right = 2, ans = 0;
	if (k == 0) {
		while (left <= n && right <= n) {
			if (a[left] == a[right]) {
				left += 2, right += 2;
				ans++;
			} else left++, right++;
		}
		ans = max(ans, cnt0);
	} else {
		while (left <= n && right <= n) {
			if (a[left] != a[right]) {
				left += 2, right += 2;
				ans++;
			} else left++, right++;
		}
	}
	cout << ans << "\n";
}

void specilC() {
	ll ans = 0, temp = 0;
	if (k == 0) {
		specilB();
		return;
	}
	for (ll i = 1; i <= n; i++) {
		if (used[i]) continue;
		temp = 0;
		for (int l = i; l <= n; l++) {
			if (i == l) temp = a[l];
			else if (a[l] == 3) temp ^= 3;
			else if (a[l] != temp) temp += a[l];
			else temp = 0;
			if (temp == k) {
				ans++;
				used[l] = true;
				break;
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) cnt1++;
		if (a[i] == 0) cnt0++;
	}
	if (cnt1 == n) specilA();
	else if (cnt1 + cnt0 == n) specilB();
	else specilC();
	return 0;
}
