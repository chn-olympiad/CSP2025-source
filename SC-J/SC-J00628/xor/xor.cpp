#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
constexpr ll MAXN = 5e5 + 5;
ll n, k, l, ans, a[MAXN];
str s_k, s[MAXN];
map<str, bool> mp;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	s_k = bitset<20>(k).to_string(), s[0] = bitset<20>(0).to_string();
	for (ll i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = bitset<20>(a[i]).to_string();
		for (ll j = 0; j < 20; ++j)
			s[i][j] = ((s[i - 1][j] ^ 48) ^ (s[i][j] ^ 48)) + 48;
	}
	mp[s[0]] = 1;
	for (ll i = 1; i <= n; ++i) {
		str fnd = bitset<20>(0).to_string();
		for (ll j = 0; j < 20; ++j)
			fnd[j] = ((s[i][j] ^ 48) ^ (s_k[j] ^ 48)) + 48;
		if (mp[fnd])
			ans++, mp.clear();
		mp[s[i]] = 1;
	}
	cout << ans << '\n';
	return 0;
}