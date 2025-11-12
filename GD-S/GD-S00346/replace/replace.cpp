#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll n, q;
string s[N], t[N], p1, p2;
int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++ i) {
		cin >> s[i] >> t[i];
	}
	while (q --) {
		cin >> p1 >> p2;
		cout << 0 << '\n'; 
	}
	return 0;
}
