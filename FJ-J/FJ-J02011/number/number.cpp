#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005], t, ans;
int k (int x) {
	for (int i = 1; i < t; i++) x *= 10;
	return x;
}
int main () {
//	freopen ("number4.in", "r", stdin);
//	freopen ("number4.out", "w", stdout);
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> s;
	for (int i = 0; i < s.size (); i++) {
		if (s[i] == '0') a[++t] = 0;
		else if (s[i] == '1') a[++t] = 1;
		else if (s[i] == '2') a[++t] = 2;
		else if (s[i] == '3') a[++t] = 3;
		else if (s[i] == '4') a[++t] = 4;
		else if (s[i] == '5') a[++t] = 5;
		else if (s[i] == '6') a[++t] = 6;
		else if (s[i] == '7') a[++t] = 7;
		else if (s[i] == '8') a[++t] = 8;
		else if (s[i] == '9') a[++t] = 9;
	}
	sort (a + 1, a + t + 1);
	for (; t > 0; t--) cout << a[t];
	return 0;
}

