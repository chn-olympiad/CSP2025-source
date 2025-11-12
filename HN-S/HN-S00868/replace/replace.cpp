#include <bits/stdc++.h>
using namespace std;
struct st {
	string s, s1;
}a[5000010];
struct st1 {
	string t, t1;
}b[5000010];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].s1;
	for (int i = 1; i <= q; i++) cin >> b[i].t >> b[i].t1;
	cout << q << ' ' << n % q << "\n";
	return 0;
}
