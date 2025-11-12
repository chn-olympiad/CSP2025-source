#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][3], t[N][3];
int dl[N], dr[N];
int tdl[N], tdr[N], sz[N];
int n, q, c1, c2;
struct node{
	int l, r;
	string s;
};
map<string, int> bh[3];
vector<node> h[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		cin >> s[i][1] >> s[i][2];
		int siz = s[i][1].size();
		sz[i] = siz;
		s[i][1] = " " + s[i][1], s[i][2] = " " + s[i][2];
		int l = 0, r = siz + 1;
		for(int j = 1; j <= siz; j ++) {
			if(s[i][1][j] != s[i][2][j]) break;
			l = j;
		}
		for(int j = siz; j >= 1; j --) {
			if(s[i][1][j] != s[i][2][j]) break;
			r = j;
		}
		dl[i] = l + 1, dr[i]= r - 1;
	}
	for(int i = 1; i <= q; i ++) {
		int ans = 0;
		cin >> t[i][1] >> t[i][2];
		int siz = t[i][1].size();
		t[i][1] = " " + t[i][1], t[i][2] = " " + t[i][2];
		int l = 0, r = siz + 1;
		for(int j = 1; j <= siz; j ++) {
			if(t[i][1][j] != t[i][2][j]) break;
			l = j;
		}
		for(int j = siz; j >= 1; j --) {
			if(t[i][1][j] != t[i][2][j]) break;
			r = j;
		}
		tdl[i] = ++ l, tdr[i] =-- r;
		for(int j = 1; j <= n; j ++) {
			if(dr[j] - dl[j] == r - l) {
				if(s[j][1].substr(dl[j], dr[j] - dl[j] + 1) == t[i][1].substr(l, r - l + 1) && s[j][2].substr(dl[j], dr[j] - dl[j] + 1) == t[i][2].substr(l, r - l + 1)) {
					int L = l - dl[j] + 1, R = r + sz[j] - dr[j];
					if(L < 1 || R > siz) {
						continue;
					}
					int flag = 1;
					for(int k = 1; k <= sz[j]; k ++) {
						if(t[i][1][L + k - 1] != s[j][1][k]) {
							flag = 0;
							break;
						}
					}
					ans += flag;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

