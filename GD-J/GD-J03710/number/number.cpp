#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string s;
char a[N];
int apos;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') a[apos++] = s[i];
	}
	sort(a, a + apos, cmp);
	cout << a;
	return 0;
} 
