#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 2e5 + 20, M = 5e6 + 20, p = 131;
int n, q;
string two[N][2];
ull has[M], hat[M], po[M];
vector <ull> haa[N][2];
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> two[i][1] >> two[i][2];
		for (int k = 1; k <= 2; k ++) {
			haa[i][k].push_back ({0});
			for (int j = 0; j < two[i][k].size (); j ++)
				haa[i][k].push_back (haa[i][k].back () * p + two[i][k][j]);
		}
	}
	po[0] = 1;
	int now = 1;
	while (q --) {
		string s, t;
		cin >> s >> t;
		int m = s.size ();
		s = " " + s, t = " " + t;
		for (int i = 1; i <= m; i ++)
			has[i] = has[i - 1] * p + s[i],
			hat[i] = hat[i - 1] * p + t[i];
		for (; now <= m; now ++)
			po[now] = po[now - 1] * p;
		int ans = 0;
		for (int i = 1; i <= m; i ++)
			for (int j = 1; j <= n; j ++)
				if (i + two[j][1].size () - 1 <= m) {
					int r = i + two[j][1].size () - 1;
//					cout << "QAQ " << has[r] - has[i - 1] << " " << haa[j][1][two[j][1].size () - 1] * po[i] << '\n';
					if (has[r] - has[i - 1] == haa[j][1][r - i + 1] * po[r - i + 1]) {
						if (has[i - 1] == hat[i - 1])
							if (has[m] - has[r] == hat[m] - hat[r])
								if (hat[r] - hat[i - 1] == haa[j][2][r - i + 1] * po[r - i + 1])
									ans ++;
					}
				}
		cout << ans << '\n';
	}
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
*/
