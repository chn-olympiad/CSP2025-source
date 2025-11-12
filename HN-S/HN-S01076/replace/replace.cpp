#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
pair<string, string> s[N];
int k[N], pre[N], nxt[N];
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	if (n <= 1000 && q <= 2000) {
		for (int i = 1; i <= n; i++) cin >> s[i].first >> s[i].second;
		while (q --> 0) {
			string t1, t2; cin >> t1 >> t2;
			int len = t1.size();
			int l = 0, r = len - 1;
			while (t1[l] == t2[l]) l++;
			while (t1[r] == t2[r]) r--;
			int le = r - l + 1;
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				int siz = s[i].first.size();
				if (siz < le) continue;
				for (int j = r - siz + 1; j <= min(l, n - siz + 1); j++) {
					int flag = 1;
					for (int k = j; k <= j + siz - 1; k++)
						if (t1[k] != s[i].first[k - j] || t2[k] != s[i].second[k - j]) {
							flag = 0;
							break;
						}
					ans += flag;
				}
			}
			cout << ans << "\n";
		}
	}
	else {
		for (int i = 1; i <= n; i++) cin >> s[i].first >> s[i].second;
		for (int i = 1; i <= n; i++) {
			int k1, k2;
			for (int j = 0; j < s[i].first.size(); j++) {
				if (s[i].first[j] == 'b') k1 = j;
				if (s[i].second[j] == 'b') k2 = j;
			}
			k[i] = k2 - k1; //ÓÒ+×ó- 
			pre[i] = min(k1, k2);
			nxt[i] = s[i].first.size() - max(k1, k2) - 1;
		}
		while (q --> 0) {
			int ans = 0;
			string t1, t2; cin >> t1 >> t2;
			int k1, k2;
			for (int j = 0; j < t1.size(); j++) {
				if (t1[j] == 'b') k1 = j;
				if (t2[j] == 'b') k2 = j;
			}
			int kk = k2 - k1; //ÓÒ+×ó- 
			int prek = max(k1, k2);
			int nxtk = t1.size() - max(k1, k2) - 1;
			for (int i = 1; i <= n; i++) {
				if (k[i] != kk || pre[i] > prek || nxt[i] > nxtk) continue;
				ans++;
			}
			cout << ans << "\n";
		}
	}
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
