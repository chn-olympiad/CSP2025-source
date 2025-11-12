#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int to[11];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	char a; int b;
	int cnt = 1;
	for (int i = 0; i < s.length(); i++) {
		a = s[i];
		if (isdigit(a)) {
			b = a - '0';
			to[b]++;
		}
	}
	bool outted = 0;
	for (int i = 9; i >= 0; i--) {
		int maxm = to[i];
		if (maxm == 0) continue;
		
		if (i == 0 && !outted && maxm > 1) {
			maxm = 1;
		}
		for (int j = 1; j <= maxm; j++) {
			cout << i;
			outted = 1;
		}	
	}
	return 0;
} 
