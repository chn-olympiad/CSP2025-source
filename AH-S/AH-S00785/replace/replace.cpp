#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
const int N = 1e5;
int n, q;
string s1[N], s2[N], t1, t2;
bool check(string str1, int x, int y, string str2, int i, int j) {
	if (x > y) return true;
	rep(k, 0, y-x) if (str1[k+x] != str2[k+i]) return false;
	return true;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	rep(i, 1, n) {
		cin >> s1[i] >> s2[i];
	}
	while(q--) {
		int ans = 0;
		cin >> t1 >> t2;
		int len = t1.size();
		if (len != t2.size()) {
			cout << 0 << endl;
			continue;
		}
		rep(i, 1, n) {
			int l = s1[i].size();
			rep(j, 0, len - l) {
				//if (len == 5 && i == 3 && j == 2) cout <<  check(t1, 2, 3, s1[i], 0, 1)<<check(t2, j, j+l-1, s2[i], 0, l-1)<<check(t1, j+l, len-1, t2, j+l, len-1) << endl;
				if (check(t1, j, j+l-1, s1[i], 0, l-1))
					if (check(t2, j, j+l-1, s2[i], 0, l-1))
						if (check(t1, j+l, len-1, t2, j+l, len-1))
							if (check(t1, 0, j-1, t2, 0, j-1))
							ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
