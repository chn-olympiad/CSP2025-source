#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000009;
string s;
int n, a[N];
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if ('0' <= s[i] && s[i] <= '9')
			a[++n] = s[i];
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) putchar(a[i]);
}