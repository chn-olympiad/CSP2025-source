#include <bits/stdc++.h>
using namespace std;

const int Base = 131;
typedef unsigned long long ll;

ll Hash(string s) {
	ll H = 0;
	for (int i = 0; i < s.size(); ++i) {
		char ch = s[i];
		H = H * Base + s[i];
	}
	return H;
}

const int MAXN = 2e5 + 100;
struct Node {
	int len;
	ll h1, h2;
}p[MAXN];

ll H1[MAXN], P[MAXN], H2[MAXN];

ll Hashing(int l, int r,ll H[], ll P[]) {
	if (l > r) return 0;
	return H[r] - H[l - 1] * P[r - l + 1];
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		p[i] = {s1.size(), Hash(s1), Hash(s2)};
	}
	
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0 << '\n';
		} else {
			P[0] = 1;
			int L = t1.size();
			for (int i = 1; i <= L; ++i) {
				P[i] = P[i - 1] * Base;
				H1[i] = H1[i - 1] * Base + t1[i - 1];
				H2[i] = H2[i - 1] * Base + t2[i - 1];
			}
			
			int ans = 0;
			for (int l = 1; l <= L; ++l) {
				if (Hashing(1, l - 1, H1, P) != Hashing(1, l - 1, H2, P)) {
					break;
				}
				for (int i = 1; i <= n; ++i) {
					int r = l + p[i].len - 1;
					if (r > L) continue;
					if (Hashing(l, r, H1, P) == p[i].h1 && Hashing(l, r, H2, P) == p[i].h2) {
						if (Hashing(r + 1, L, H1, P) == Hashing(r + 1, L, H2, P)) {
							++ans;
						}
					}
				}
			}
			
			cout << ans << '\n';
		}
	}
}
/*
yangli 1:
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
