#include <bits/stdc++.h>
#define il inline
using namespace std;
il void read(int &x) {
	x = 0; bool f = 0; char c = getchar();
	while (!isdigit(c)) f |= (c == '-'), c = getchar();
	while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x = f ? -x : x;
}

const int Maxn = 200005;
int n, q;
string s[Maxn][3];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n), read(q);
	for (int i = 1; i <= n; i ++)
		cin >> s[i][1] >> s[i][2];
	if (n <= 1000 && q <= 1000) {
		while (q --) {
			string t1, t2; cin >> t1 >> t2;
			string tmp = t1;
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				int lens = s[i][1].size(), lent = t1.size();
				for (int l = 0, r = l + lens - 1; r <= lent; ) {
					if (tmp.substr(l, lens) == s[i][1]) {
						tmp.erase(l, lens);
						tmp.insert(l, s[i][2]);
						if (tmp == t2) ans ++;
						tmp = t1;
					}
					l ++, r ++;
				}
			}
			cout << ans << "\n";
		}
	} else {
		while (q --) {
			string t1, t2; cin >> t1 >> t2;
			puts("0");
		}
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
