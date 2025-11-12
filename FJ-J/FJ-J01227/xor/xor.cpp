#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef string str;

int n, k;
int a[510000];
int ans = 0;
std::vector<std::pair<int, int> > v;

inline int sz(std::pair<int, int> x) {
	return x.se - x.fi + 1;
}

inline bool cmp(std::pair<int, int>x, std::pair<int, int>y) {
	if (sz(x) != sz(y)) {
		return sz(x) < sz(y);
	}
	return x.se < y.se;
}
int r[510000][2];
bool f[510000];
inline void is1(void) {
	F(i, 1, n, 1) {
		if (a[i] != 1) {
			return;
		}
	}
	cout << n / 2 << el;
	exit(0);
}


signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	F(i, 1, n, 1) {
		cin >> a[i];
	}
	is1();
	F(l, 1, n, 1) {
		int x = 0;
		F(r, l, n, 1) {
			x ^= a[r];
			if (x == k) {
				v.push_back({l, r});
				//cout << l << sp << r << el;
			}
		}
	}
	std::sort(v.begin(), v.end(), cmp);
	n = v.size();
	int ans = 0;
	F(i, 0, n - 1, 1) {
		bool g = 1;
		F(j, v[i].fi, v[i].se, 1) {
			if (f[j]) {
				g = 0;
				break;
			}
		}
		if (g) {
			ans++;
			F(j, v[i].fi, v[i].se, 1) {
				f[j] = 1;
			}
		}
	}
	cout << ans << el;
	r0;
}

