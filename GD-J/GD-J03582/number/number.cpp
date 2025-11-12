#include <bits/stdc++.h>

using namespace std;

bool vis;
int cnt[20];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;

	for (auto c : s) {
		if (c >= '0' && c <= '9') {
			cnt[c - '0'] ++;
		}
	}

	for (int i = 9; i >= 0; --i) {
		if (!cnt[i]) continue;
		vis = true;
		while (cnt[i]--) cout << i;
	}
	
	return 0;
} 
