#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
string s1[maxn], s2[maxn];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> s1[i] >> s2[i];
	while(q--) {
		int ans = 0;
		string a, b;
		cin >> a >> b;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j + s1[i].size() - 1 < a.size(); ++j) {
				string c = "";
				for(int k = 0; k < j; ++k)
					c += a[k];
				for(int k = j; k <= j + s1[i].size() - 1; ++k)
					c += s2[i][k - j];
				for(int k = j + s1[i].size(); k < a.size(); ++k)
					c += a[k];
				if(c == b) ++ans;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
