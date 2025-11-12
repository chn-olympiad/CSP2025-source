#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10, mod = 998244353;

string L[maxn][3];
string s[maxn][3];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;scanf("%d%d", &n, &q);
	for (int i = 1;i <= n;i ++) cin >> s[i][1] >> s[i][2];
	if (n <= 110) {
		for (int i = 1;i <= q;i ++) {
			cin >> L[i][1] >> L[i][2];
			int ok = 0;
			for (int l = 0;l < (int)L[i][1].size();l ++) {
				for (int r = l + 1;r < (int)L[i][2].size();r ++) {
					bool flag = 1;
					for (int ch = 0;ch < (int)L[i][1].size();ch ++) {
						if (ch < l) {
							if (L[i][2][ch] != L[i][1][ch]) {
								flag = 0;
								break;
							}
						} else if (ch <= r) {
							if (s[i][2][ch - l] != L[i][2][ch] || s[i][1][ch - l] != L[i][1][ch]) {
								flag = 0;
								break;
							}
						} else {
							if (L[i][2][ch] != L[i][1][ch]) {
								flag = 0;
								break;
							}
						}
					}
					ok += flag;
				}
			}
			printf("%d\n", ok);
		}
	} else {
		for (int i = 1;i <= q;i ++ ) puts("0");
	}
	return 0;
}