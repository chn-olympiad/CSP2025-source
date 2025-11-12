#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 2e5 + 5;

int n, q;
struct aa {
	string s1, s2;
} a[N];

int main () {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	cin >> n >> q;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
		sum += a[i].s1.size();
		sum += a[i].s2.size();
	}
	for (string s1, s2; q--;) {
		cin >> s1 >> s2;
		if (s1.size() != s2.size()) {
			cout << "0\n";
			continue;
		}
		int ans = 0;
		int l = 0;
		for (; l < s1.size() && s1[l] == s2[l]; l++);
		int r = s1.size() - 1;
		for (; r >= 0 && s1[r] == s2[r]; r--);
		for (int i = 1; i <= n; i++) {
			for (int j = max(0, (int)(r - a[i].s1.size() + 1)); j <= l && j + a[i].s1.size() - 1 < s1.size(); j++) {
				if (s1.substr(j, a[i].s1.size()) == a[i].s1 && s2.substr(j, a[i].s1.size()) == a[i].s2) {
					ans++;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
