#include<bits/stdc++.h>
using namespace std;
string s, ans;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> s;
	for (auto &i : s)
		if (i >= '0' && i <= '9')
			ans += i;
	sort(ans.begin(), ans.end(), greater<char>());
	cout << ans;
	return 0;
}