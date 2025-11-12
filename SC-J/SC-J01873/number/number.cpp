#include<bits/stdc++.h>
#define AC return 0
const int MAXN = 1e6 + 5;
using namespace std;

int t, a[MAXN];
string s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[t++] = s[i] - '0';
	}
	// for 1~3
	if (t < 2) {
		cout << a[0];
		AC;
	}
	sort(a, a + t);
	for (int i = t - 1; i >= 0; i--) {
		cout << a[i];
	}
	AC;
}