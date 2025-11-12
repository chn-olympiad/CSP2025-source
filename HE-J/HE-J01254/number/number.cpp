#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 5;
string s;
int a[150];
int main() {
	freopen("number.in", "r" , stdin);
	freopen("number.out", "w" , stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		int c = s[i] - '0';
		if (c >= 0 && c <= 9)
			a[c] ++;
	}
	for (int i = 9; i >= 0; i --)
		for (int j = a[i]; j >= 1; j --)
			cout << i;
	return 0;
}

