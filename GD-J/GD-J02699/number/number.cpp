#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	string t = "";
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t += s[i];
		}
	}
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	cout << t << "\n";
	return 0;
} 
