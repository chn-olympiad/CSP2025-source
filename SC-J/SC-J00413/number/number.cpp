#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(long long i = 0; i < s.length(); ++i) {
		if(!(s[i] <= '9' && s[i] >= 0)) {
			s.erase(s.begin() + i, s.begin() + i + 1);
			i--;
		}
	}
	sort(s.begin(), s.end());
	for(int i = s.length() - 1; i >= 0; --i) {
		cout << s[i];
	}
}