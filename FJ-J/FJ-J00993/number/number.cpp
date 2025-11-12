#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N], len;

bool cmp (int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			a[++len] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + len, cmp);
	for (int i = 1; i <= len; i++) {
		printf("%d", a[i]);
	}
	return 0;
}

