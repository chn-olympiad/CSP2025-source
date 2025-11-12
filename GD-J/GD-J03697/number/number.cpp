#include <bits/stdc++.h>

using namespace std;

string s;
int ans[1000007], ai, ci;

bool cmp (int x, int y) {
	return x > y;
}

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			ans[++ai] = (int)(s[i] - '0');
		}
	}
//	cout << "OUT|||\n";
	sort(ans + 1, ans + ai + 1, cmp);
	for (int i = 1; i <= ai; i++) {
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}
