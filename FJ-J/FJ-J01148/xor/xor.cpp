#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n, k, a[500005], q[500005], ans = 0;
set <int> s;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		q[i] = q[i - 1] ^ a[i];
	}
	s.insert(0);
	for (int i = 1; i <= n; i++) {
		if (s.count(q[i] ^ k)) {
			ans++;
			s.clear();
		}
		s.insert(q[i]);
	}
	cout << ans << endl;
	return 0;
}
