#include <bits/stdc++.h>
using namespace std;
long long n, q, ans;
int main() {
	// freopen("replace.in", "r", stdin);
	// freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	const long long N = n;
	string s[N + 10][5];
	for (long long i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
	if (q == 1) {
		string t1, t2;
		cin >> t1 >> t2;
		long long len = t1.size();
		vector <long long> has1(len), has2(len);
		long long pw = 114, mod = 998244353;
		has1[0] = t1[0] - 'a' + 1, has2[0] = t2[0] - 'a' + 1;
		for (int i = 1; i < len; i++) {
			has1[i] = (has1[i - 1] * pw
		}
	}
	return 0; 
}
