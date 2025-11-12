#include <bits/stdc++.h>
using namespace std;

int a[500003];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= a[i-1];
	}
	vector<pair<int, int>> c; // R,L
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j)
			if((a[j] ^ a[i-1]) == k)
				c.push_back({j, i});
	sort(begin(c), end(c));
	long long ans = 0;
	for(int i = 0, R = 0; i < (int)c.size(); ++i)
		if(c[i].second > R) {
			++ans;
			R = c[i].first;
		}
	cout << ans << endl;
	return 0;
}
