#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;

	sort(s.begin(), s.end(), greater<char>());

	for (int i = 0; i < (int)s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			cout << s[i];
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
