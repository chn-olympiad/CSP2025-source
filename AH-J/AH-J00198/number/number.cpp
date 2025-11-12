#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
int num[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	for (auto ch : s) {
		if (isdigit(ch)) {
			++ num[ch - '0'];
		}
	}
	per(i, 9, 0) {
		rep(j, 1, num[i]) {
			cout << i;
		}
	}
	cout << '\n';
	return 0;
}
