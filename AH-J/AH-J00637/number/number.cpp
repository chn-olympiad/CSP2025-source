#include <bits/stdc++.h>
using namespace std;
string s, ans;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (char c : s)
		if (c >= '0' && c <= '9')
			ans.push_back(c);
	sort(ans.begin(), ans.end(), greater<char>());
	cout << ans << '\n';
	return 0;
}
