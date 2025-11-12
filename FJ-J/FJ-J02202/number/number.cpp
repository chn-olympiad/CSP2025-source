#include <bits/stdc++.h>
using namespace std;

int a[1000005], ans;
string s;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) a[++ans] = s[i] - '0';
	}
	sort(a + 1, a + ans + 1, cmp);
	for (int i = 1; i <= ans; i++) cout << a[i];
	return 0;
}
