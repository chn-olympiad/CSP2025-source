#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[20];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> s;
	for (char ch : s)
		if (isdigit(ch)) cnt[ch - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = cnt[i]; j; j--) cout << i;
	cout << "\n";
	return 0;
}

