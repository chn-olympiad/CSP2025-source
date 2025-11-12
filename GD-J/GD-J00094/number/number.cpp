#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	vector<long long> num(10, 0);
	for (auto ch : s) {
		if (isdigit(ch)) num[ch - '0']++;
	}
	for (int i = 9 ; i >= 0 ; --i) {
		while (num[i] > 0) {
			cout << i;
			num[i]--;
		}
	}
	return 0;
}
