#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 1e6 + 2;

int n, a[N];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++) if (isdigit(s[i])) a[++n] = s[i] - '0';
	sort(a + 1, a + 1 + n);
	for (int i = n;i >= 1;i--) cout << a[i];
	cout << endl;
	return 0;
}

