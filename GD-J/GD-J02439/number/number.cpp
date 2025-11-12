#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> ints;
	ints.reserve(s.size() / 2);
	for (const char &i : s) {
		if (isdigit(i)) {
			ints.push_back(i - '0');
		}
	}
	sort(ints.begin(), ints.end(), greater<int>());
	for (const int i : ints) {
		cout << i;
	}
	return 0;
}
