#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, M = 5e6 + 5;
int n, q;
string s1[N], s2[N];
int nxt[M];
map <int, bool> b;

int main () {

	ios::sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> s1[i] >> s2[i];
	while (q--) {
		string t1 = "", t2 = "";
		cin >> t1 >> t2;
		int l1 = t1.length (), l2 = t2.length ();
		if (l1 != l2) cout << 0 << '\n';
		else {
			int l, r;
			for (int i = 0; i < l1; ++i) if (t1[i] != t2[i]) { l = i + 1; break; }
			for (int i = l1 - 1; i >= 0; --i) if (t1[i] != t2[i]) { r = i + 1; break; }
			int ans = 0;
			for (int i = 1; i <= n; ++i) {
				vector <int> v1, v2;
				string T1 = s1[i] + "#" + t1, T2 = s2[i] + "#" + t2;
				int len1 = T1.length (), L = s1[i].length ();
				T1 = " " + T1, T2 = " " + T2;
				v1.clear (), v2.clear ();
				
				for (int k = 2, j = 0; k <= len1; ++k) {
					while (j && T1[k] != T1[j + 1]) j = nxt[j];
					if (T1[k] == T1[j + 1]) j++;
					nxt[k] = j;
					if (nxt[k] == L) v1.push_back (k - L - 1); 
				}
				for (int k = 2; k <= len1; ++k) nxt[k] = 0; 
				for (int k = 2, j = 0; k <= len1; ++k) {
					while (j && T2[k] != T2[j + 1]) j = nxt[j];
					if (T2[k] == T2[j + 1]) j++;
					nxt[k] = j;
					if (nxt[k] == L) v2.push_back (k - L - 1); 
				}
				bool flag = false;
				for (int j : v1) if (j >= r && j - L + 1 <= l) b[j] = true;
				for (int j : v2) if (b[j]) flag = true;
				if (flag) ans++;
				for (int j : v1) b[j] = false;
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
