// wc,sort卡了我半天，30分钟做题里面20分钟在调sort 
// 100pts
#include <iostream>
#include <algorithm>
using namespace std;

bool check_digit(char c) {
	return c >= '0' && c <= '9';
}
bool cmp(int a, int b) {
	return a > b;
}
string number(string s)  {
	int wei = 0, a[1000005];
	string ans = "";
	for (int i = 0; i < s.size(); i ++) {
		if (check_digit(s[i])) {
			a[wei] = s[i] - '0';
			wei ++;
		}
	}
	sort(a, a + wei, cmp);
	for (int i = 0; i < wei; i ++) {
		ans += a[i] + '0';
	}
	return ans;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	cout << number(s);
	return 0;
}
// CSP-J2025 rp++!
