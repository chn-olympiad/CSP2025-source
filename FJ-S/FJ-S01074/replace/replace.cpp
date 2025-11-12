#include <bits/stdc++.h>
#define sp " "
#define el "\n"
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef string str;

int n, q;
std::map<str, str> c;

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	while (n--) {
		str s, t;
		cin >> s >> t;
		c[s] = t;
	}
	while (q--) {
		str s, t;
		cin >> s >> t;
		int ans = 0;
		int m = s.size();
		str x = "";
		F(i, -1, m - 1, 1) {// x end
			if (i >= 0) {
				x += s[i];
			}
			str y = "", z = s.substr(i + 1);
			reverse(z.begin(), z.end());
			F(j, i + 1, m - 1, 1) {// y end
				y += s[j];
				z.pop_back();
				if (c[y] != "") {
					str r = z;reverse(r.begin(), r.end());
					str nw = x + c[y] + r;
					if (nw == t) {
						ans++;
					}
				}
			}
		}
		cout << ans << el;
	}
	r0;
}
