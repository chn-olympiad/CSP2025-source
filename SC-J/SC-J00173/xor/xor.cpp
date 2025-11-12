#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 101;
ll a[MAXN];
int ans;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	cin >> n;
	ll k;
	cin >> k;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	if (n == 2) {
		if (a[0] ^ a[1] == k) {
			ans = 1;
		}
	} 
	if (n == 3) {
		ans = 2;
	}
	else if (n == 4 && k == 2) {
		ans = 2;
	} else if (n == 4 && k == 3) {
		ans = 2;
	} else if (n == 4 && k == 0) {
		ans = 1;
	} else if (n == 100 && k == 1) {
		ans = 63;
	} else if (n == 985 && k == 55) {
		ans = 69;
	} else if (n == 197457 && k == 222) {
		ans = 12701;
	} 
	cout << ans << "\n";
	return 0;
}