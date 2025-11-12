#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, K;

struct Info {
	int v[3];
} a[100005];
bool cmp(const Info &a, const Info &b) {
	return a.v[K] > b.v[K];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].v[0] >> a[i].v[1] >> a[i].v[2];
	}
	int fres = -1;
	for (int K = 0; K < 3; ++K) {
		int ans = 0;
		multiset<int> s1, s2;
		int tot3 = 0;
		int i1, i2;
		if (K == 0) i1 = 1, i2 = 2;
		if (K == 1) i1 = 0, i2 = 2;
		if (K == 2) i1 = 0, i2 = 1;
		for (int i = 1; i <= n; ++i) {
			bool flg = 0;
			if (a[i].v[i1] < a[i].v[i2]) flg = 1, swap(s1, s2), swap(a[i].v[i1], a[i].v[i2]);
			int c1 = a[i].v[i1], c2 = a[i].v[i2], c3 = a[i].v[K];
			if (s1.size() == n / 2) { // 但是满了
				 // 考虑从 1 集合中换一个出来
				int t = *(s1.rbegin());
				c1 += t;
			}
			if (c1 >= c2 && c1 >= c3) {
				ans += c1;
				if (s1.size() == n / 2) {
					int t = *(s1.rbegin());
					s2.insert(-t);
					s1.erase(s1.find(t));
					s1.insert(-a[i].v[i1] + max(a[i].v[i2], a[i].v[K]));
				} else {
					s1.insert(-a[i].v[i1] + max(a[i].v[i2], a[i].v[K]));
				}
			} else if ( c2 >= c1 && c2 >= c3) {
				ans += c2;
			} else {
				assert(c3 >= c1 && c3 >= c2);
				ans += c3;
				tot3++;
			}
			if (flg) {
				swap(s1, s2);
				swap(a[i].v[i1], a[i].v[i2]);
			}
		}
		if (tot3 <= n / 2) fres = max(fres, ans);
	}
	cout << fres << "\n";
}

signed main() {
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int tc; cin >> tc;
	while (tc--) solve();
	return 0;
}

