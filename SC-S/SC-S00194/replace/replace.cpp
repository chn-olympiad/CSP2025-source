#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200009;
int n, q, txb, ch[N];
map<string, map<string, int> > mp;
string a[N], b[N], A, B, t, s, tt, ss;
bool read(string &x) {
	x = "";
	int c; int f = 0;
	while (c < 'a' || 'z' < c) c = getchar();
	while ('a' <= c && c <= 'z') f += (c == 'b'), x += c, c = getchar();
	return f == 1;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q, txb = 1;
	for (int i = 1; i <= n; i++) {
		txb &= read(a[i]), txb &= read(b[i]);
	}
	if (n <= 200) {
		for (int i = 1; i <= n; i++)
			mp[a[i]][b[i]]++;
		for (int i = 1; i <= q; i++) {
			read(A), read(B);
			if (A.size() != B.size()) {
				cout << "0\n";
				continue;
			}
			int n = A.size(), ans = 0, l = 0, r = n - 1;
			while (A[l] == B[l]) l++;
			while (A[r] == B[r]) r--;
			s = A.substr(l, r - l + 1), t = B.substr(l, r - l + 1);
			for (int i = l; i >= 0; i--) {
				ss = s, tt = t;
				for (int j = r; j < n; j++){
					ans += mp[ss][tt];
					if (j < n - 1) ss += a[j + 1], tt += b[j + 1];
				}
				if (i > 0) s = a[i - 1] + s, t = b[i - 1] + t;
			}
			cout << ans << '\n';
		}
		exit(0);
	}
	if (txb) {
		for (int i = 1; i <= n; i++) {
			int n = a[i].size(), l = 0, r = n - 1;
			while (a[i][l] == b[i][l]) l++;
			while (a[i][r] == b[i][r]) r--;
			ch[r - l + 1]++;
		}
		for (int i = 1; i <= q; i++) {
			read(A), read(B);
			if (A.size() != B.size()) cout << "0\n";
			else {
				int n = A.size(), l = 0, r = n - 1;
				while (A[l] == B[l]) l++;
				while (A[r] == B[r]) r--;
				cout << ch[r - l + 1] << '\n';
			}
		}
	}
}/*

*/