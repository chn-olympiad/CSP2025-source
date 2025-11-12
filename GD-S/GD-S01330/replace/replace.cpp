#include <bits/stdc++.h>
using namespace std;
// replace
int n, q;
const int N = 2e3 + 5;
string has[N][2];
string H[N][2];
int len[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j < 2; j ++ )
			cin >> has[i][j];
	while (q -- ) {
		string s1; cin >> s1;
		string s2; cin >> s2;
		int L = s1.length();
		int cnt = 0;
		for (int p = 1; p <= n; p ++ ) {
			int l = len[p];
			for (int i = 0; i + l - 1 < L; i ++ ) {
				bool flg = 1;
				for (int k = 0; k < l; k ++ )
					if (s1[i + k] != has[p][0][k] || s2[i + k] != has[p][1][k]) {
						flg = 0;
						break;
					}
				if (flg) {
					for (int k = i + l; k < L; k ++ )
						if (s1[k] != s2[k]) {
							flg = 0;
							break;
						}
				}
				if (flg) cnt ++ ;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
} 
