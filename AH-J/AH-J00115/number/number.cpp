#include <bits/stdc++.h>
using namespace std;
string s;
int a[12];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(isdigit(s[i])) a[s[i] - '0']++;
	}
	for(int i = 9; i >= 0; i--) {
		while(a[i] > 0) putchar(i + '0'), a[i]--;
	}
	return 0;
}
