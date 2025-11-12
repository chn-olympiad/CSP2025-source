#include<bits/stdc++.h>
#define int long long
using namespace std;
int read();
const int N = 2e5 + 10;
struct Node {
	string s1, s2;
} a[N];
map<int, int> mp;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	for (int i = 1; i <= q; i++) {
		string l1, l2;
		cin >> l1 >> l2;
		if (l1.size() != l2.size()) {
			cout << "0\n";
			continue;
		}
		int ll = l1.find('b');
		int rr = l2.find('b');
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			int l = a[j].s1.find('b');
			int r = a[j].s2.find('b');
			if (ll - rr == l - r && ll >= l && rr >= r && l1.size() - ll >= a[j].s1.size() - l && l2.size() - rr >= a[j].s2.size() - r) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
int read() {
	int Ca = 0;
	char Cr = ' ';
	int Cf = 1;
	while (Cr < '0' || Cr > '9') {
		Cr = getchar();
		if (Cr == '-') {
			Cf = -1;
		}
	}
	while (Cr >= '0' && Cr <= '9') {
		Ca = Ca * 10 + Cr - '0';
		Cr = getchar();
	}
	return Cf * Ca;
}