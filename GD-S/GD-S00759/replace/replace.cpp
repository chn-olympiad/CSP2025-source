#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1 << 30;

const int N = 2e5 + 3;

string s[2][N], t[2][N];
int p[2][N * 100], L[N], R[N], ans[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[0][i] >> s[1][i];
	for (int i = 1; i <= q; i++) cin >> t[0][i] >> t[1][i];
	for (int i = 1; i <= q; i++) {
		int l = -1, sz = t[0][i].size();
		while (l + 1 < sz && t[0][i][l + 1] == t[1][i][l + 1]) ++l;
		int r = sz;
		while (r - 1 >= 0 && t[0][i][r - 1] == t[1][i][r - 1]) --r;
		L[i] = l + 1;
		R[i] = r + 1;
	}
	for (int k = 1; k <= n; k++) {
		int Ts = s[0][k].size();
		for (int i = 0; i <= 1; i++) for (int j = 1; j <= q; j++) s[i][k] += "#" + t[i][j];
		for (int i = 0; i <= 1; i++) {
			int sz = s[i][k].size();
			int tmp = -1, pre = -1, cnt = 0;
			p[i][0] = -1;
			for (int j = 1; j < sz; j++) {
				while (tmp >= 0 && s[i][k][tmp + 1] != s[i][k][j]) tmp = p[i][tmp];
				if (s[i][k][tmp + 1] == s[i][k][j]) ++tmp;
				p[i][j] = tmp;
				if (s[i][k][j] == '#') pre = j, ++cnt;
				else if (pre > 0 && i > 0 && tmp == Ts - 1 && p[0][j] == Ts - 1)
					ans[cnt] += j - pre >= R[cnt] - 1 && j - tmp - pre <= L[cnt] + 1;
			}
		}
		s[0][k].clear();
		s[1][k].clear();
	}
	for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
