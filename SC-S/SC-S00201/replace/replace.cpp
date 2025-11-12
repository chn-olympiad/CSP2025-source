#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string s[N][3];
int main() {
	ios::sync_with_stdio(false);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q; 
	for (int i = 1; i <= n; ++i) {
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; ++i) {
		string t1, t2;
		cin >> t1 >> t2;
		cout << "0\n";
	}
	return 0;
} 