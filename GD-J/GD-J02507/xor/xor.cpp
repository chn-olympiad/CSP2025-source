#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const ll N = 5e5 + 10;
ll k, n, a[N], ret;
vector<PII> ans;

bool cmp(PII x, PII y) {
	return x.second < y.second;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (ll i = 1ll;i <= n;++i) cin >> a[i];
	if (n <= 1000ll && k != 1ll) {
		for (ll i = 1ll;i <= n;++i) {
			ll sum = 0ll;
			for (ll j = i;j <= n;++j) {
				sum ^= a[j];
				if (sum == k) ans.emplace_back(i, j);
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		ll r = 0ll;
		for (auto i : ans) if (i.first > r) ++ret, r = i.second;
		cout << ret;
	} else {
		for (ll i = 1ll;i <= n;++i) ret += (a[i] == 1ll);
		cout << ret;
	}
	return 0;
}

/*
WT* why is T3 so hard?
tanxinly think, the sub sequence should be as short as possible
Seems can be dfs for the 2^20,
You're right, but polygon's 40% seems to be much easier
n^2 subsequnces，不能相交，求最多能覆盖多少个？
经典贪心，右端点最小
*/
