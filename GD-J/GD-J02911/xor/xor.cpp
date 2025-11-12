#include <bits/stdc++.h>
using namespace std;

int n, k, a[500010], sum, ans;
vector <pair <int, int> > p;
bool check(int l ,int r) {
	for (int i = 0, ll, rr; i < p.size(); i++) {
		ll = p[i].first; rr = p[i].second;
		if (l >= ll && l <= rr) return true;
		else if (r >= ll && r <= rr) return true;
		else if (ll >= l && ll <= r) return true;
		else if (rr >= l && rr <= r) return true;
	}
	return false;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int l = 1, r = l + i - 1; r <= n; l++, r++) {
			if (check(l, r)) continue;
			sum = a[l];
			for (int j = l + 1; j <= r; j++) {
				sum = sum ^ a[j];
			}
			if (sum == k) {
				p.push_back({l, r});
				ans++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
