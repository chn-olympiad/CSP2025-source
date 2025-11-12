#include<bits/stdc++.h>
#define nmf(i,s,e) for(int i=s;i<=e;i++)
#define ref(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
string s[2][200005];
int n, q;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	nmf(i, 1, n)
	cin >> s[0][i] >> s[1][i];
	while (q--) {
		string t[2];
		cin >> t[0] >> t[1];
		int ans = 0;
		nmf(i, 1, n) {
			if (s[0][i].size() > t[0].size())continue;
			nmf(j, 0, t[0].size() - s[0][i].size()) {
//				cout << t[0].substr(j, s[0][i].size()) << endl;
				if (t[0].substr(j, s[0][i].size()) == s[0][i] ) {
					nmf(k, j, j + s[1][i].size() - 1)swap(t[0][k], s[1][i][k - j]);
					if (t[0] == t[1])ans++;
					nmf(k, j, j + s[1][i].size() - 1)swap(t[0][k], s[1][i][k - j]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}