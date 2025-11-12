#include <iostream>
#include <string> 
using namespace std;
const int MAXS = 12;
long long num[MAXS];
string s, res;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			num[s[i] - '0']++;
		} 
	}
	for (int i = 9; i >= 0; i--) {
		string tmp;
		tmp.resize(num[i], char(i + '0'));
		res = res + tmp;
	}
	while (res[0] == '0') {
		res.replace(0, 1, "");
	}
	if (res == "") {
		res = "0";
	}
	cout << res;
	return 0;
}
