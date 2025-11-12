#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 5;

int n, q;
string s[N], s2[N];

bool check(int x, string t, string t2, int k) {
	string now;
	for (int i = 0; i < k; ++i)
		now += t[i];
	now += s2[x];
	for (int i = k + s2[x].size(); i < t.size(); ++i)
		now += t[i];
//	cout << now << '\n';
	return (now == t2);
}

bool ck (string t, int x, int k) {
	for (int i = 0; i < s[x].size(); ++i)
		if (t[i + k] != s[x][i]) return 0;
	return 1;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s[i] >> s2[i];
	for (int i = 1; i <= q; ++i) {
		string t, t2;
		cin >> t >> t2;
		int ans = 0, m = t.size();
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (ck(t, j, k))
					ans += check(j, t, t2, k);
			}
//			cout << ans << ' ' << j << '\n';
		}
		cout << ans << '\n';
	}
	
	return 0;
}


