#include <bits/stdc++.h>

using namespace std;

namespace zcq_qwq {
	const int N = 200000 + 5;
	
	string a[N], b[N];
	
	int n, m;
	
	void main() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
		}
		for (int i = 1; i <= m; i++) {
			string s, t;
			cin >> s >> t;
			int res = 0;
			for (int j = 1; j <= n; j++) {
				if (s.find(a[j]) == -1) continue;
				for (int k = 0; k < (int)s.size(); k++) {
					if (k + a[j].size() - 1 >= s.size()) break;
					string d = s.substr(k, a[j].size());
					if (d == a[j]) {
						int pos = k;
						string p = s.substr(0, pos);
						string q = s.substr(pos + a[j].size(), s.size() - pos - a[j].size());
						string ans = p + b[j] + q;
						if (ans == t) {
							res++;
						}
//						cout << p << " " << " " << b[j] << " " << q << endl;
					} 
				}
			}
			cout << res << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	zcq_qwq::main();
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

