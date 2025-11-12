#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
using namespace std;
int n, m;
string a[200005], b[200005], t;
long long ans;
unordered_map<unsigned long long, bool> mp;
inline unsigned long long hs(string s) {
	unsigned long long res = 0;
	for (int i = 0; i < s.size(); i++) res = res * 131ull + 1ull * (s[i] - 'a' + 1);
	return res;
}
void dfs(string s, int depth) {
	if (s == t) {
		ans++;
		return;
	}
	if (depth == 1) return;
	if (mp[hs(s)]) return;
	mp[hs(s)] = true;
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i + a[k].size() - 1 < n; i++) {
			int j = i + a[k].size() - 1;
			bool flag = true;
			for (int kk = i; kk <= j; kk++) {
				if (s[kk] != a[k][kk - i]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				string ss = s.substr(0, i) + b[k] + s.substr(j + 1, n - j + 1);
				dfs(ss, depth + 1);
			}
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s >> t;
		ans = 0;
		mp.clear();
		dfs(s, 0);
		cout << ans << '\n';
	}
	return 0;
}
