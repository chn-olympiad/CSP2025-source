#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
void work() {
	ll n;
	cin >> n;
	vector<ll> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
	vector<pair<ll, ll>> pos(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		ll mx = max(a[i], max(b[i], c[i]));
		if(a[i] == mx) {
			ll res = mx - max(b[i], c[i]);
			pos[i] = {1, res};
		}
		else if(b[i] == mx) {
			ll res = mx - max(a[i], c[i]);
			pos[i] = {2, res};
		}
		else if(c[i] == mx) {
			ll res = mx - max(a[i], b[i]);
			pos[i] = {3, res};
		}
	}
	ll cnt[4] = {0}, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(pos[i].first == 1) {
			ans += a[i];
			cnt[1]++;
		} else if(pos[i].first == 2) {
			ans += b[i];
			cnt[2]++;
		} else {
			ans += c[i];
			cnt[3]++;
		}
	}
	if(cnt[1] < n/2 && cnt[2] < n/2 && cnt[3] < n/2) {
		cout << ans << '\n';
		return;
	}
	if(cnt[1] > n/2) {
		vector<int> add;
		for(int i = 1; i <= n; i++) {
			if(pos[i].first == 1) add.push_back(pos[i].second);
		}
		sort(add.begin(), add.end());
		ll po = 0;
		while(cnt[1] > n/2) {
			cnt[1]--;
			ans -= add[po];
			po++;
		}
		cout << ans << '\n';
	} else if(cnt[2] > n/2) {
		vector<int> add;
		for(int i = 1; i <= n; i++) {
			if(pos[i].first == 2) add.push_back(pos[i].second);
		}
		sort(add.begin(), add.end());
		ll po = 0;
		while(cnt[2] > n/2) {
			cnt[2]--;
			ans -= add[po];
			po++;
		}
		cout << ans << '\n';
	} else {
		vector<int> add;
		for(int i = 1; i <= n; i++) {
			if(pos[i].first == 3) add.push_back(pos[i].second);
		}
		sort(add.begin(), add.end());
		ll po = 0;
		while(cnt[3] > n/2) {
			cnt[3]--;
			ans -= add[po];
			po++;
		}
		cout << ans << '\n';
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	while(T--) {
		work();
	}
	return 0;
}
