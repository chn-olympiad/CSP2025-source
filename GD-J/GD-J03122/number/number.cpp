#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s;
vector<int> a;

int cmp(const int x, const int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a.push_back(int(s[i] - '0'));
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i ++) {
		cout << a[i];
	}
	return 0;
}
