#include <bits/stdc++.h>
using namespace std;

string s;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	string result = "";
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			result += s[i];
		}
	}
	stable_sort(result.begin(), result.end(), cmp);
	cout << result;
	
	return 0;
}
