#include <bits/stdc++.h>
using namespace std;

int n,q,f[10000005];
string s[200005][2],t1,t2,t;
vector<int> g[200005];

int main() {
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++) cin >> s[i][0] >> s[i][1];
	while (q--) {
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {cout << 0 << endl;continue;}
		int l,r = -1;
		long long ans = 0;
		for (int i = 0;i < t1.size();i++) {
			if (r > -1 && r < i - 1 && t1[i] != t2[i]) {r = -1;break;}
			if (r == -1 && t1[i] != t2[i]) l = r = i;
			if (r == i - 1 && t1[i] != t2[i]) r++;
		}
		if (r == -1) {cout << 0 << endl;continue;}
		for (int i = 1;i <= n;i++) g[i].clear();
		for (int j = 1;j <= n;j++) {
			t = " " + s[j][0] + "#" + t1;
			int m = t.size() - 1;
			f[1] = 0;
			for (int i = 2;i <= m;i++) {
				f[i] = f[i - 1] + 1;
				while (f[i] > 1 && t[f[i]] != t[i]) f[i] = f[f[i] - 1] + 1;
				if (t[f[i]] != t[i]) f[i]--;
			}
			for (int i = s[j][0].size() + 2;i <= m;i++)
				if (f[i] == s[j][0].size() && i - 2 * s[j][0].size() - 1 <= l && i - s[j][0].size() - 2 >= r) g[j].push_back(i);
		}
		for (int j = 1;j <= n;j++) {
			t = " " + s[j][1] + "#" + t2;
			int m = t.size() - 1;
			f[1] = 0;
			for (int i = 2;i <= m;i++) {
				f[i] = f[i - 1] + 1;
				while (f[i] > 1 && t[f[i]] != t[i]) f[i] = f[f[i] - 1] + 1;
				if (t[f[i]] != t[i]) f[i]--;
			}
			int cur = 0;
			for (int i = s[j][1].size() + 2;i <= m;i++)
				if (f[i] == s[j][1].size()) {
					while (cur < g[j].size() && g[j][cur] < i) cur++;
					if (cur < g[j].size() && g[j][cur] == i) ans++;
				}
		}
		cout << ans << endl;
	}
	return 0;
}