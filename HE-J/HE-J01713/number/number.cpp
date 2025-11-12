#include <bits/stdc++.h>
using namespace std;
multiset<char, greater<char> > st;
bool cmp(char a, char b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	sort(s.begin(), s.end(), cmp);
	int l = 0, r = s.size();
	while (l < r) {
		int mid = (l + r) >> 1;
		if (isdigit(s[mid])) r = mid - 1;
		else l = mid + 1;
	}
	while(islower(s[l]))l++;
	while(isdigit(s[l]))l--;
	cout << s.substr(l + 1, s.size() - l);
	return 0;
}
