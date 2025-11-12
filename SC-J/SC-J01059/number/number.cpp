#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
string s;
vector<int> num;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char i : s) {
		if (isdigit(i)) {
			num.push_back(i ^ '0');
		}
	}
	sort(num.begin(), num.end(), greater<int>());
	for (int i : num) {
		cout << i;
	}
	cout << '\n';
	return 0;
}