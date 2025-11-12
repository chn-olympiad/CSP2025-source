#include <bits/stdc++.h>

using namespace std;

string str;
int s[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	for (char i : str)
		if ('0' <= i && i <= '9')
			s[i - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= s[i]; j++)
			cout << i;
	cout << '\n';
	return 0;
}