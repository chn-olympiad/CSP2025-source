#include <bits/stdc++.h>
using namespace std;

string s, sc = "";
int num[15];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len-1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int idx = int(s[i] - '0');
			num[idx]++;
		}
	}
	bool flag = 0;
	for (int i = 9; i >= 0; i--) {
		if (num[i] >= 1) {
			if (i > 0) {
				flag = 1;
			}
			for (int j = 1; j <= num[i]; j++) {
				sc += to_string(i);
			}
		}
	}
	if (flag == 0) {
		cout << 0 << '\n';
	} else {
		cout << sc << '\n';
	}
	return 0;
}
