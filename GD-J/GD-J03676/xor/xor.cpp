#include <bits/stdc++.h>
using namespace std;
struct inv {
	int l, r;
	bool operator < (const inv &x) const {
		return r < x.r;
	}
};
int n, k, a[500005], sxor[500005], ans;
vector<inv> v;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sxor[i] = sxor[i - 1] ^ a[i];
		if (sxor[i] == k) v.push_back({1, i});
	}
	for (int l = 2; l <= n; ++l) {
		for (int r = l; r <= n; ++r) {
			//cout << l << " " << r << " " << ((sxor[r] ^ sxor[l - 1]) == k) << endl;
			if ((sxor[r] ^ sxor[l - 1]) == k) v.push_back({l, r});
		}
	}
	sort(v.begin(), v.end());
	int l = 0, r = 0;
	//cout << v.size() << endl;
	for (int i = 0; i < v.size(); ++i) {
		//cout << v[i].l << " " << v[i].r << endl;
		if (v[i].l <= r) continue;
		l = v[i].l;
		r = v[i].r;
		++ans;
		if (r == n) break;
	}
	cout << ans;
	return 0;
}
