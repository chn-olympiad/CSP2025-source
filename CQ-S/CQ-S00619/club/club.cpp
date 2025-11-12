#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;
int a[3][N], n, id[N];
void solve(void) {
	int cnt[5];
	cnt[0] = cnt[1] = cnt[2] = 0;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[0][i] >> a[1][i] >> a[2][i];
		int tmp = max({a[0][i], a[1][i], a[2][i]});
		if (tmp == a[0][i]) 
			cnt[0] ++, id[i] = 0;
		else if (tmp == a[1][i])
			cnt[1] ++, id[i] = 1;
		else cnt[2] ++, id[i] = 2;
		ans += tmp;
	}
	if (cnt[0] <= n / 2 && cnt[1] <= n / 2 && cnt[2] <= n / 2) {
		cout << ans << '\n';
		return;
	}
	int pos;
	if (cnt[0] > n / 2) 
		pos = 0;
	else if (cnt[1] > n / 2)
		pos = 1;
	else 
		pos = 2;
	vector<ll> vec;
	for (int i = 1; i <= n; ++i) {
		if (id[i] == pos) {
			int mx = -1;
			for (int j = 0; j < 3; ++j) {
				if (j == pos) continue;
				mx = max(a[j][i], mx);
			}
			vec.push_back(mx - a[pos][i]);
		}
	}
	sort(vec.begin(), vec.end(), greater<ll>());
	int now = 0;
	while (cnt[pos] > n / 2) {
		ans += vec[now];
		now ++;
		cnt[pos] --;
	}
	cout << ans << '\n';
}
int main() {
    FASTIO;
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}
// 100 pts
