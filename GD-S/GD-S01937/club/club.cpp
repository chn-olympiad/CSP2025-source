#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100100][3];
long long ans;
vector<ll> cnt1, cnt2, cnt3, del;

void solve() {
	cnt1.clear();
	cnt2.clear();
	cnt3.clear();
	del.clear();
	ans = 0;
	memset(a, 0, sizeof(a));
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
		ll d = max({a[i][0], a[i][1], a[i][2]});
		ans += d;
		if (d == a[i][0])
			cnt1.push_back(i);
		else if (d == a[i][1])
			cnt2.push_back(i);
		else
			cnt3.push_back(i);
	}
	if ((ll)cnt1.size() > n / 2)
		for (auto i : cnt1)
			del.push_back(max(a[i][1] - a[i][0], a[i][2] - a[i][0]));
	else if ((ll)cnt2.size() > n / 2)
		for (auto i : cnt2)
			del.push_back(max(a[i][0] - a[i][1], a[i][2] - a[i][1]));
	else if ((ll)cnt3.size() > n / 2)
		for (auto i : cnt3)
			del.push_back(max(a[i][1] - a[i][2], a[i][0] - a[i][2]));
	sort(del.begin(), del.end());
	ll l = del.size();
	while (l > n / 2)
		ans += del[--l];
	printf("%lld\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t;
	scanf("%lld", &t);
	while (t--)
		solve();
}
/*
##### ##### ##### ####  #     #   # ##### #   #
#     #   # #   # #   # #     #   # #     # ## 
#  ## #   # #   # #   # #     #   # #     ##   
#   # #   # #   # #   # #     #   # #     # ## 
##### ##### ##### ####  ##### ##### ##### #   #
*/