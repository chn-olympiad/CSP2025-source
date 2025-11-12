#include <bits/stdc++.h>

#define ll long long
#define in(x) scanf ("%lld", &x)

using namespace std;

ll t;
ll n;
ll s1;
ll s2;
ll s3;
ll l1[100005];
ll l2[100005];
ll l3[100005];
bool vis[100005];

struct node {
	ll id;
	ll val1;
	ll val2;
	ll val3;
	ll k1;
	ll k2;
	ll maxn;
	ll mid;
	ll minn;
	ll maxn_id;
	ll mid_id;
	ll minn_id;
};

node a[100005];

struct node2 {
	ll k;
	ll idd;
	ll iddd;
};

node2 b[100005];

bool cmp(node x, node y) {	
	if (x.maxn == y.maxn) {
		if (x.mid == y.mid) {
			return x.minn > y.minn;
		} else {
			return x.mid > y.mid;
		}
	} else {
		return x.maxn > y.maxn;
	}
}

bool cmp2(node2 x, node2 y) {
	return x.k < y.k;
}

void work(ll i) {
	if (a[i].val1 > a[i].val2) {
		if (a[i].val1 > a[i].val3) {
			a[i].maxn = a[i].val1;
			a[i].maxn_id = 1;
			if (a[i].val2 > a[i].val3) {
				a[i].mid = a[i].val2;
				a[i].minn = a[i].val3;
				a[i].mid_id = 2;
				a[i].minn_id = 3;
			} else {
				a[i].mid = a[i].val3;
				a[i].minn = a[i].val2;
				a[i].mid_id = 3;
				a[i].minn_id = 2;
			}
		} else {
			a[i].maxn = a[i].val3;
			a[i].maxn_id = 3;
			a[i].mid = a[i].val1;
			a[i].minn = a[i].val2;
			a[i].mid_id = 1;
			a[i].minn_id = 2;
		}
	} else {
		if (a[i].val2 > a[i].val3) {
			a[i].maxn = a[i].val2;
			a[i].maxn_id = 2;
			if (a[i].val3 > a[i].val1) {
				a[i].mid = a[i].val3;
				a[i].minn = a[i].val1;
				a[i].mid_id = 3;
				a[i].minn_id = 1;
			} else {
				a[i].mid = a[i].val1;
				a[i].minn = a[i].val3;
				a[i].mid_id = 1;
				a[i].minn_id = 3;
			}
		} else {
			a[i].maxn = a[i].val3;
			a[i].maxn_id = 3;
			a[i].mid = a[i].val2;
			a[i].minn = a[i].val1;
			a[i].mid_id = 2;
			a[i].minn_id = 1;
		}
	}
	a[i].k1 = a[i].maxn - a[i].mid;
	a[i].k2 = a[i].maxn - a[i].minn;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	in(t);
	while (t--) {
		in(n);
		s1 = 0;
		s2 = 0;
		s3 = 0;
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			a[i].id = i;
			in(a[i].val1);
			in(a[i].val2);
			in(a[i].val3);
			work(i);
			l1[i] = 0;
			l2[i] = 0;
			l3[i] = 0;
			vis[i] = 0;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (ll i = 1; i <= n; i++) {
			if (a[i].maxn_id == 1) {
				s1++;
				l1[s1] = i;
				ans += a[i].maxn;
			} else {
				if (a[i].maxn_id == 2) {
					s2++;
					l2[s2] = i;
					ans += a[i].maxn;
				} else {
					s3++;
					l3[s3] = i;
					ans += a[i].maxn;
				}
			}
		}
		//cout << s1 << " " << s2 << " " << s3 << endl;
		if (s1 <= n / 2 && s2 <= n / 2 && s3 <= n / 2) {
			cout << ans << endl;
			continue;
		}
		if (s1 > n / 2) {
			for (ll i = 1; i <= s1; i++) {
				b[i * 2 - 1].k = a[l1[i]].k1;
				b[i * 2].k = a[l1[i]].k2;
				b[i * 2 - 1].idd = a[l1[i]].id;
				b[i * 2].idd = a[l1[i]].id;
				b[i * 2 - 1].iddd = a[l1[i]].mid_id;
				b[i * 2].iddd = a[l1[i]].minn_id;
			}
			sort(b + 1, b + 1 + s1 * 2, cmp2);
			//for (ll i = 1; i <= s1 * 2; i++) {
			//	cout << b[i].idd << " " << b[i].k << " " << b[i].iddd << endl;
			//}
			ll m = s1;
			for (ll i = 1; i <= s1 * 2; i++) {
				if (vis[b[i].idd]) {
					continue;
				}
				if (b[i].iddd == 2) {
					if (s2 < n / 2) {
						s2++;
						m--;
						ans -= b[i].k;
						vis[b[i].idd] = 1;
					}
				}
				if (b[i].iddd == 3) {
					if (s3 < n / 2) {
						s3++;
						m--;
						ans -= b[i].k;
						vis[b[i].idd] = 1;
					}
				}
				if (m <= n / 2) {
					break;
				}
			}
		}
		if (s2 > n / 2) {
			for (ll i = 1; i <= s2; i++) {
				b[i * 2 - 1].k = a[l2[i]].k1;
				b[i * 2].k = a[l2[i]].k2;
				b[i * 2 - 1].idd = a[l2[i]].id;
				b[i * 2].idd = a[l2[i]].id;
				b[i * 2 - 1].iddd = a[l2[i]].mid_id;
				b[i * 2].iddd = a[l2[i]].minn_id;
			}
			sort(b + 1, b + 1 + s2 * 2, cmp2);
			//for (ll i = 1; i <= s2 * 2; i++) {
			//	cout << b[i].idd << " " << b[i].k << " " << b[i].iddd << endl;
			//}
			ll m = s2;
			for (ll i = 1; i <= s2 * 2; i++) {
				if (vis[b[i].idd]) {
					continue;
				}
				if (b[i].iddd == 1) {
					if (s1 < n / 2) {
						s1++;
						m--;
						ans -= b[i].k;
						vis[b[i].idd] = 1;
					}
				}
				if (b[i].iddd == 3) {
					if (s3 < n / 2) {
						s3++;
						m--;
						ans -= b[i].k;
						vis[b[i].idd] = 1;
					}
				}
				if (m <= n / 2) {
					break;
				}
			}
		}
		if (s3 > n / 2) {
			for (ll i = 1; i <= s3; i++) {
				b[i * 2 - 1].k = a[l3[i]].k1;
				b[i * 2].k = a[l3[i]].k2;
				b[i * 2 - 1].idd = a[l3[i]].id;
				b[i * 2].idd = a[l3[i]].id;
				b[i * 2 - 1].iddd = a[l3[i]].mid_id;
				b[i * 2].iddd = a[l3[i]].minn_id;
			}
			sort(b + 1, b + 1 + s3 * 2, cmp2);
			ll m = s3;
			for (ll i = 1; i <= s3 * 2; i++) {
				if (vis[b[i].idd]) {
					continue;
				}
				if (b[i].iddd == 2) {
					if (s2 < n / 2) {
						s2++;
						m--;
						ans -= b[i].k;
						vis[b[i].idd] = 1;
					}
				}
				if (b[i].iddd == 1) {
					if (s1 < n / 2) {
						s1++;
						m--;
						ans -= b[i].k;
						vis[b[i].idd] = 1;
					}
				}
				if (m <= n / 2) {
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
