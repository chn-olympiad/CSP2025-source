#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	freopen("number4.in", "r", stdin);
//	freopen("t.out", "w", stdout);
	cin >> s;
	for (auto ch : s)
		if (ch < 'a')
			t += ch;
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	cout << t << endl;
	return 0;
}
