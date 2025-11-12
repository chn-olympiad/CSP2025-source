//I want to see myself at luogu
// my luogu id:993044
// my luogu name:Like_Amao
//91
//78
//13
//169
//100 + 100 + 25 + 40 = 265 pts
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int ans[N];
int read();
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	int cnt = 0;
	for (int i = 0 ; i < len ; i ++) {
		if (s[i] >= '0' and s[i] <= '9') {
			ans[++ cnt] = s[i] - '0';
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = cnt ; i >= 1 ; i --) {
		cout << ans[i];
	}
	return 0;
}
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
