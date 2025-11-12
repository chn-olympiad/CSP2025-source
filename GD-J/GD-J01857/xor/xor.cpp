#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k; cin >> n >> k;
	vector<int> a(n), pre(n + 1);
	for (int i = 0; i < n; i++) cin >> a[i], pre[i + 1] = pre[i] ^ a[i];
	
	int ans = 0, last = -1;
	vector<int> buc(1 << 20, -1);
	for (int i = 0; i < n; i++) {
		buc[pre[i]] = max(buc[pre[i]], i);
		if (buc[pre[i + 1] ^ k] > last) {
			ans++, last = i;
		}
	}
	cout << ans;

	return 0;
}
