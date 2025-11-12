#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t = 0;
ll n = 0;
ll ans = 0;
bool f1 = 0;
bool f2 = 0;

//ll dp[1000100] = {0};

struct node {
	ll f = 0;
	ll s = 0;
	ll th = 0;
}a[1000100];

bool check (ll x, ll y, ll z) {
	return (x <= n / 2) and (y <= n / 2) and (z <= n / 2);
}

void dfs (ll fa, ll sa, ll ta, ll g, ll i) {
	if (i > n) {
		if (check(fa, sa, ta)) {
			ans = max(ans, g);
		}
		return;
	}
	dfs(fa + 1, sa, ta, g + a[i].f, i + 1);
	dfs(fa, sa + 1, ta, g + a[i].s, i + 1);
	dfs(fa, sa, ta + 1, g + a[i].th, i + 1);
}

bool cmp (node x, node y) {
	return x.f > y.f;
}

bool cmp2 (node x, node y) {
	if (x.f > x.s) {
		return x.f > y.f;
	}
	else {
		return x.s > y.s;
	}
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		cin >> n;
		for (ll j = 1; j <= n; j++) {
			cin >> a[j].f >> a[j].s >> a[j].th;
			if (a[j].s != 0 or a[j].th != 0) {
				f1 = 1;
			}
			if (a[j].th != 0) {
				f2 = 1;
			}
		}
		if (f1 == 0) {
			sort(a + 1, a + n + 1, cmp);
			for (ll i = 1; i <= n / 2; i++) {
				ans += a[i].f;
			}
			cout << ans << '\n';
			continue;
		}
		if (f2 == 0) {
			ll st = 0;
			ll nd = 0;
			sort(a + 1, a + n + 1, cmp2);
			for (ll i = 1; i <= n; i++) {
				if (a[i].f > a[i].s and st < n / 2) {
					st += 1;
					ans += a[i].f;
				}
				else if (nd < n / 2) {
					ans += a[i].s;
				}
			}
			continue;
		}
		dfs(0, 0, 0, 0, 1);
		cout << ans << '\n';
		ans = 0;

//		memset(dp, 0, sizeof(dp));
//		ll st = 0;
//		ll nd = 0;
//		ll rd = 0;
//		for (ll j = 1; j <= n; j++) {
//			if (st < n / 2) {
//				st += 1;
//				dp[j] = dp[j - 1] + a[j].f;
//			}
//			if (nd < n / 2) {
//				nd += 1;
//				if (dp[j - 1] + a[j].s > dp[j]) {
//					st -= 1;
//				}
//				else {
//					nd -= 1;
//				}
//				dp[j] = max(dp[j], dp[j - 1] + a[j].s);
//			}
//			if (rd < n / 2) {
//				rd += 1;
//				if (dp[j - 1] + a[j].th > dp[j]) {
//					nd -= 1;
//				}
//				else {
//					rd -= 1;
//				}
//				dp[j] = max(dp[j], dp[j - 1] + a[j].th);
//			}
//		}
//		cout << dp[n] << '\n';

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
