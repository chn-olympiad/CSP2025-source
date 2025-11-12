#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e5 + 10;
ll t, n, ans;
array<array<ll, 4>, N> a;
array<ll, N> id;

ll val1(ll x) {
	return a[x][1] - max(a[x][2], a[x][3]);
}

ll val2(ll x) {
	return a[x][2] - max(a[x][3], a[x][1]);
}

ll val3(ll x) {
	return a[x][3] - max(a[x][1], a[x][2]);
}

bool cmp1(ll x, ll y) {
	return val1(x) > val1(y);
}

bool cmp2(ll x, ll y) {
	return val2(x) > val2(y);
}

bool cmp3(ll x, ll y) {
	return val3(x) > val3(y);
}

void init_data() {
	cin >> n;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		id[i] = i;
	}
}

ll solve1() {
	ll ans = 0, cnt = 0;
	sort(id.begin() + 1, id.begin() + n + 1, cmp1);
	for(ll i, j = 1; j <= n; j++) {
		i = id[j];
		if(val1(i) >= 0 && cnt < n / 2) {
			cnt++, ans += a[i][1];
		} else {
			ans += a[i][1] - val1(i);
		}
	}
	return cnt == n / 2 ? ans : -1;
}

ll solve2() {
	ll ans = 0, cnt = 0;
	sort(id.begin() + 1, id.begin() + n + 1, cmp2);
	for(ll i, j = 1; j <= n; j++) {
		i = id[j];
		if(val2(i) >= 0 && cnt < n / 2) {
			cnt++, ans += a[i][2];
		} else {
			ans += a[i][2] - val2(i);
		}
	}
	return cnt == n / 2 ? ans : -1;
}

ll solve3() {
	ll ans = 0, cnt = 0;
	sort(id.begin() + 1, id.begin() + n + 1, cmp3);
	for(ll i, j = 1; j <= n; j++) {
		i = id[j];
		if(val3(i) >= 0 && cnt < n / 2) {
			cnt++, ans += a[i][3];
		} else {
			ans += a[i][3] - val3(i);
		}
	}
	return cnt == n / 2 ? ans : -1;
}

ll get_ans() {
	ll ans = max({solve1(), solve2(), solve3()});
	// cerr << solve1() << ' ' << solve2() << ' ' << solve3() << '\n';
	if(ans == -1) {
		ans = 0;
		for(ll i = 1; i <= n; i++) {
			ans += max({a[i][1], a[i][2], a[i][3]});
		}
	}
	return ans;
}

int main() {
	freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while(t--) {
		init_data();
		cout << get_ans() << '\n';
	}
}
