#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long
struct node {
	ll l, r;
};
using namespace std;
vector<ll> a;
bool vis[(ll)5e5 + 10];
vector<node> xo;
bool cmp(node k1, node k2) {
	return k1.r - k1.l + 1 < k2.r - k2.l + 1;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(vis, false, sizeof vis);
	int n; ll k; cin >> n >> k;
	if (n <= 1050) {
		for (int i = 0; i < n; ++i) {
		ll x; cin >> x;
		if (x != 0)
			a.push_back(x);
		}
		//cout << k << endl;
		for (int i = 0; i < n; ++i) {
			int l = a[i];
			for (int j = i; j < n; ++j) {
				if (j != i)
					l ^= a[j];
				if (l == k) {
					node u;
					u.l = i, u.r = j;
					xo.push_back(u);
				}
			}
		}
		ll ans = xo.size();
		//cout << xo.size() << endl;
		sort(xo.begin(), xo.end(), cmp);
		node u = xo[0];
		for (int i = u.l; i <= u.r; ++i) {
			vis[i] = true;
		}
		for (int i = 1; i < xo.size(); ++i) {
			node u = xo[i];
			bool flag = false;
			for (int j = u.l; j <= u.r; ++j) {
				if (vis[j] == true) {
					--ans;
					flag = true;
					break;
				}
			}
			if (flag == false) {
				for (int j = u.l; j <= u.r; ++j) {
					vis[j] = true;
				}
			}
		}
		cout << ans << endl;
	}
	else {
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			if (x == k)
				ans++;
		}
		cout << ans << endl;
	}
}
