#include <bits/stdc++.h>
using namespace std;
string s;
int a[11];

int main () {
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0;i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[(s[i] - '0')]++;
		}
	}
	for (int j = 9;j >= 0; --j) {
		if (a[j] != 0) {
			int ans = a[j];
			while (ans) {
				ans--;
				cout << j;
			}
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
