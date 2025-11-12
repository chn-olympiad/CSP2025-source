#include<bits/stdc++.h>
using namespace std;

int l;
string s;
int a[20];


int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.length();
	for (int i = 0; i < l; i ++) {
		char c = s[i];
		if (c <= '9' || c >= '0') {
			a[int(c - '0')] += 1;
		}
	}
	for (int i = 9; i >= 0; i --) {
		for (int j = 0; j < a[i]; j ++) {
			cout << i;
		}
	}
	return 0;
}
