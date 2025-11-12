#include<bits/stdc++.h>
using namespace std;

string s;
int cnt[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> s;

	for (int i = 0; i < (int)s.size(); i++) {
		if (isdigit(s[i])) {
			cnt[s[i] - '0']++;
		}
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = cnt[i]; j > 0; j--) {
			cout << i;
		}
	}

	cout << endl;

	return 0;
}