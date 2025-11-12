#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 2e5 + 5, M = 2.5e6 + 5, B = 911, K = 2240;
int n, q, id[M];
ull bas[M], h1[M], h2[M];
unordered_map<ull, int>mp[K];
vector<int>len;
string s1[N], s2[N];
ull Hash(string&s)
{
	ull ha = 0;
	for (int i = 0; i < s.size(); ++i) {
		ha = ha * B + s[i];
	}
	return ha;
}
bool en;
int main()
{
	freopen("replace.in", "r", stdin);
#ifdef xu
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n------------------" << endl;
#else
	freopen("replace.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bas[0] = 1;
	for (int i = 1; i <= 2500000; ++i) {
		bas[i] = bas[i - 1] * B;
	}
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		len.emplace_back(s1[i].size());
	}
	sort(all(len));
	len.erase(unique(all(len)), len.end());
	for (int i = 0; i < len.size(); ++i) {
		id[len[i]] = i + 1;
	}
	for (int i = 1; i <= n; ++i) {
		++mp[id[s1[i].size()]][Hash(s1[i]) * bas[s1[i].size()] + Hash(s2[i])];
	}
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int ts = t1.size();
		int L = INT_MAX, R = INT_MIN;
		for (int i = 1; i <= ts; ++i) {
			if (t1[i - 1] != t2[i - 1]) {
				L = min(L, i);
				R = max(R, i);
			}
		}
		for (int i = 1; i <= ts; ++i) {
			h1[i] = h1[i - 1] * B + t1[i - 1];
			h2[i] = h2[i - 1] * B + t2[i - 1];
		}
		ll ans = 0;
		auto hsh1 = [&](int l, int r) {
			return h1[r] - h1[l - 1] * bas[r - l + 1];
		};
		auto hsh2 = [&](int l, int r) {
			return h2[r] - h2[l - 1] * bas[r - l + 1];
		};
		for (int le : len) {
			for (int i = max(1, R + 1 - le); i <= L && i + le - 1 <= ts; ++i) {
				ull hid = hsh1(i, i + le - 1) * bas[le] + hsh2(i, i + le - 1);
				auto it = mp[id[le]].find(hid);
				if (it != mp[id[le]].end()) {
					ans += it -> second;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}