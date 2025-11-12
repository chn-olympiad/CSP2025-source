#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	stable_sort(s.begin(), s.end(), greater<char>());
	string r;
	bool ze = 0;
	for (char c: s) {
		if (c == '0' && ze) {
			r += c;
		}
		if (c >= '1' && c <= '9') {
			r += c;
			ze = 1;
		}
	}
	if (!ze) r += '0';
	cout << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
