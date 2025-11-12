#include <bits/stdc++.h>
using namespace std;

const int N = 5e2+10;

int n, m;
string s;
int c[N], p[N];

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1;i<= n;i++) {
		cin >> c[i]; p[i] = i;
	} int ans = 0;
	do {
		int No = 0, Yes = 0;
		for (int i = 1;i<= n;i++) {
			if (No >= c[p[i]]) { No++; continue; }
			if (s[i] == '0') No++;
			else Yes++;
		}
		if (Yes >= m) ans++;
	} while (next_permutation(p+1, p+n+1));
	cout << ans << endl;
	return 0;
}
