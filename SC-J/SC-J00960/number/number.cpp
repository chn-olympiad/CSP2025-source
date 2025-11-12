#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<char> a;
	
	for (int i = 0; i < s.size(); ++i) {
		if ('0' <= s[i] && s[i] <= '9') {
			a.emplace_back(s[i]);
		}
	}
	
	sort(a.begin(), a.end());
	
	for (int i = a.size() - 1; i >= 0; --i) {
		cout << a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}