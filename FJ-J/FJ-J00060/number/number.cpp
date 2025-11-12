#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

string s;
vector<int> numbers;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char c: s) {
		if ('0' <= c && c <= '9') {
			numbers.push_back(c - '0');
		}
	}
	sort(numbers.begin(), numbers.end());
	if (numbers[numbers.size() - 1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = numbers.size() - 1; i >= 0; --i) {
		cout << numbers[i];
	}
	return 0;
}
