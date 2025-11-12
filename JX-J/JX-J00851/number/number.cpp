#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int cnt[12];
char s[N];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> s + 1;
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		if (isdigit(s[i]))
			++cnt[s[i] - '0'];
	for (int i = 9; ~i; --i)
		while (cnt[i]--) cout << i;
	return 0;
}
/*
g++ -o number number.cpp -O2 -std=c++14 -static

*/