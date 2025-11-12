// Æ´Êý(number) 
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000005;
string s;
int t, len, a[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') a[++t] = s[i] - '0';
	}
	sort(a + 1, a + t + 1);
	for (int i = t; i >= 1; i--) printf ("%d", a[i]);
	return 0;
}
