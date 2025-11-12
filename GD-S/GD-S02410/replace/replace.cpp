#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

const int N = 2e5 + 7;
const int M = 5e6 + 7;
const long long bas = 13331;
const long long mod = 998244353;

int n, q;
string s[N][2];
int pre[N], suf[N];

struct Query {
	int x, y, dif, id;
} qry[N];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	for (int i = 1; i <= n; i ++)
		cin >> s[i][0] >> s[i][1];
	while (q --) {
		string t1, t2;
		cin >> t1 >> t2;
		int len = (int) t1.size(), res = 0;
		for (int i = 1; i <= n; i ++) {
			bool F = 0;
			for (int j = 0; j <= len - (int) s[i][0].size(); j ++) {
				bool flg = 1;
				for (int k = 0; k < len; k ++) {
					if (k >= j && k < j + (int) s[i][0].size()) {
						flg &= (s[i][0][k - j] == t1[k] && s[i][1][k - j] == t2[k]);
					} else {
						flg &= (t1[k] == t2[k]);
					}
				}
				F |= flg;
			}
			res += F;
		}
		cout << res << '\n';
	}
	return 0;
}
