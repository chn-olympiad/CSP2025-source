#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e5 + 5;
string s1[MAXN], s2[MAXN];
int n, q;
string a, b;
vector<int> ap[26];
bool check(int zz, int l, int len) {
	string s = "";
	if (l != 0)
		s = s + a.substr(0, l);
	s += s2[zz];
	int r = l + len;
	if (l + len - 1 != a.size())
		s += a.substr(l + len, (a.size() - r));
//	cout << zz << ' ' << l << ' ' << len<< ' ' << s << ' ' << b << '\n';
	if (b == s)
		return true;
	return false;
}
int main() {
#if DEBUG
	freopen(".\\replace\\replace3.in", "r", stdin);
//	freopen(".\\replace\\replace1.out", "w", stdout);
#else
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	ios::sync_with_stdio(0), cin. tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s1[i] >> s2[i];
//	return 0;
	while (q--) {
		cin >> a >> b;
		int len = a.size();
		int res = 0;
		for (int l = 0; l < len; ++l)
			for (int r = l + 1; r < len; ++r) {
				int len = r - l + 1;
					for (int i = 1; i <= n; ++i)
						if (a.substr(l, len) == s1[i] && check(i, l, len))
							++res;
			}
		cout << res << '\n';
	}
	return 0;
}