#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

string s;
int cnt0;
int tong[15];

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); ++ i) {
		if (!isdigit(s[i])) continue;
		if (s[i] == '0') cnt0 ++;
		else {
			tong[s[i] - '0'] ++;
		}
	}
	for (int num = 9; num >= 1; -- num) {
		while (tong[num] --) cout << num;
	}
	while (cnt0 --) cout << '0';
	return 0;
}