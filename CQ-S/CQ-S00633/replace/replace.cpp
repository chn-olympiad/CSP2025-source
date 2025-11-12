#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
const int Mod = 998244353, mod = 1e9 + 7, N = 2e5 + 10, P = 131, L = 5e6 + 10;
map<pair<string, string>, int> mp;
unordered_map <int, int> mp3;
vector<int> mp2[L];
bool fb = 1;
string s[N][2], t[N][2];
int sum1, sum2, d[N][2];
ull po[L], te[N][2];
vector<ull> h[N][2];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	po[0] = 1;
	for (int i = 1; i < L; i++) po[i] = po[i - 1] * P;
	for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; i++) cin >> t[i][0] >> t[i][1];
	for (int i = 1; i <= n; i++) {
		int l = s[i][0].size();
		h[i][0].emplace_back(s[i][0][0] - 'a'), h[i][1].emplace_back(s[i][1][0] - 'a');
		for (int j = 1; j < l; j++) h[i][0].emplace_back(h[i][0].back() * P + s[i][0][j] - 'a'), h[i][1].emplace_back(h[i][1].back() * P + s[i][1][j] - 'a');
	}
	for (int i = 1; i <= q; i++) {
		int ans = 0;
		int l = t[i][0].size();
		te[0][0] = t[i][0][0] - 'a', te[0][1] = t[i][1][0] - 'a';
		for (int j = 1; j < l; j++) te[j][0] = te[j - 1][0] * P + t[i][0][j] - 'a', te[j][1] = te[j - 1][1] * P + t[i][1][j] - 'a';
		for (int j = 1; j <= n; j++) {
			int p = s[j][0].size();
			vector<int> pp;
			for (int k = 0; k <= l - p; k++) {
				if (k) {
					if (h[j][0].back() == te[k + p - 1][0] - te[k - 1][0] * po[p] && h[j][1].back() == te[k + p - 1][1] - te[k - 1][0] * po[p]) pp.emplace_back(k);
				} else {
					if (h[j][0].back() == te[p - 1][0] && h[j][1].back() == te[p - 1][1]) pp.emplace_back(0);
				}
			}
			for (int& v : pp) {
				if (te[v - 1][0] != te[v - 1][1]) continue;
				if (te[l - 1][0] - te[v + p - 1][0] * po[l - v - p] != te[l - 1][1] - te[v + p - 1][1] * po[l - v - p]) continue;
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

