#include <bits/stdc++.h>

using namespace std;

string str;
int cnt[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			cnt[str[i] - '0']++;
		}
	}
	
	bool pre = false;
	for (int i = 9; i >= 0; i--) {
		if (i == 0 && pre == false) {
			cout << "0";
		} else {
			pre |= (cnt[i] != 0);
			for (int j = 1; j <= cnt[i]; j++) {
				cout << i;
			}
		}
	}
	
	cout << "\n";
	
	return 0;
}
