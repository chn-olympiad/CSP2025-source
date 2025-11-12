#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int maxn = 5e5;
constexpr int maxrange = 1 << 20;
int n, k;
vector<int> t[maxrange + 10], tt[maxrange + 10];
int a[maxn + 10];
int pre[maxn + 10], suf[maxn + 10];
int dp[maxn + 10], mp[maxn + 10];
int df[maxn + 10], mf[maxn + 10]; 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) pre[i] = pre[i-1] ^ a[i];
	for (int i = n; i >= 1; --i) suf[i] = suf[i+1] ^ a[i];
	for (int i = 0; i <= n; ++i) t[pre[i]].emplace_back(i);
	for (int i = n + 1; i >= 1; --i) tt[suf[i]].emplace_back(i);
	for (int i = 1; i <= n; ++i) {
		int lst = k ^ pre[i];
		mp[i] = mp[i-1];
		if (t[lst].empty()) continue;
		auto pos = lower_bound(t[lst].begin(), t[lst].end(), i);
		if (pos == t[lst].begin()) continue;
		--pos;
		dp[i] = mp[*pos] + 1;
		mp[i] = max(mp[i], dp[i]);
	} 
	for (int i = n; i >= 1; --i) {
		int nxt = k ^ suf[i];
		mf[i] = mf[i+1];
		if (tt[nxt].empty()) continue;
		auto pos = upper_bound(tt[nxt].begin(), tt[nxt].end(), i);
		if (pos == tt[nxt].end()) continue;
		df[i] = mf[*pos] + 1;
		mf[i] = max(mf[i], df[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) ans = max(ans, mp[i] + mf[i+1]);
	cout << ans << "\n";
	return 0;
}

