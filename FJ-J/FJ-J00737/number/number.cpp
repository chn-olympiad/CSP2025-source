#include <bits/stdc++.h>	//100

using namespace std;

const int N = 2e2 + 10;

int cnt[N];

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size(); i ++) {
		if ('0' <= s[i] && s[i] <= '9') {
			cnt[char(s[i])] ++;
		}
	}
	
	for (char i = '9'; i >= '0'; i --) {
		for (int j = 1; j <= cnt[int(i)]; j ++) {
			cout << i;
		}
	}
	cout << "\n";

	return 0;
}

