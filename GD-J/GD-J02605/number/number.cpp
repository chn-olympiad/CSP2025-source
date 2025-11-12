#include<bits/stdc++.h>
#define foR(i, x, y) for (int i = x; i >= y; i--)
#define FOr(i, x, y) for (int i = x; i < y; i++)
#define For(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
int cnt[15];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	For(i, 0, s.size())
		if (s[i] <= '9' && s[i] >= '0') cnt[s[i] - '0']++;
	foR(i, 9, 0) For(j, 1, cnt[i]) cout << i;
}
