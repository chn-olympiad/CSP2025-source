#include <iostream>
using namespace std;

int x[10];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, ans; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			x[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		ans += string(x[i], i + '0');
	}
	cout << ans << '\n';
	return 0;
}
