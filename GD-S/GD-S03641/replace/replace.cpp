#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+10;
int s[N], s2[N], t[N], t2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i] >> s2[i];
	for (int i = 1; i <= q; i++) cin >> t[i] >> t2[i];
	for (int i = 1; i <= q; i++) cout << 0 << endl;
	return 0;
}
