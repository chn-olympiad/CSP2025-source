#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int hsh[N];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
		hsh[s[i]] ++;
	for (int i = '9'; i >= '0'; i --)
		for (int j = 1; j <= hsh[i]; j ++)
			cout << char(i);
	return 0;
}

