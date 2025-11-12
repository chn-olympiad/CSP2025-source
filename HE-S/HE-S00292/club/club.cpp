#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;
const ll N = 1e5 + 10;
struct node {
	ll x, y, z;
}a[N];
ll n, ans;
std::vector < ll > vec[3];

inline bool cmp (ll &x, ll &y) {
	return a[x].x > a[y].x;
}

void Main() {
	std::cin >> n;
	ans = 0;
	vec[0].clear(), vec[1].clear(), vec[2].clear();
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i].x >> a[i].y >> a[i].z;
		ll mx = std::max(std::max(a[i].x, a[i].y), a[i].z);
		ans += mx;
		if (mx == a[i].x) vec[0].push_back(i);
		else if (mx == a[i].y) vec[1].push_back(i);
		else vec[2].push_back(i);
	}
	ll mx_size = std::max(std::max(ll(vec[0].size()), ll(vec[1].size())), ll(vec[2].size()));
	if (mx_size <= n / 2) {
		std::cout << ans << '\n';
		return ;
	}
	ll opt = -1;
	if (mx_size == ll(vec[0].size())) opt = 0;
	else if (mx_size == ll(vec[1].size())) opt = 1;
	else opt = 2;
	for (ll x : vec[opt]) {
		if (opt == 0) a[x].x = std::max(a[x].y, a[x].z) - a[x].x;
		else if (opt == 1) a[x].x = std::max(a[x].x, a[x].z) - a[x].y;
		else a[x].x = std::max(a[x].x, a[x].y) - a[x].z;
	}
	std::sort(vec[opt].begin(), vec[opt].end(), cmp);
	for (ll i = 0; i < mx_size - n / 2; i++) 
		ans += a[vec[opt][i]].x;
	std::cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	ll T = 1;
	std::cin >> T;
	while (T--) Main();
	return 0;
}
