#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string replace(string source, string &s1, string &s2) {
	for (int i = 0; i <= source.length() - s1.length(); i ++)
		if (source.substr(i, s1.length()) == s1)
			return source.substr(0, i) + s2 + source.substr(i + s1.length(), source.length() - s1.length() - i);
	return "";
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int result, n, q;
	string s1, s2;
	cin >> n >> q;
	vector< pair<string, string> > rules(n); 
	for (int i = 0; i < n; i ++)
		cin >> rules[i].first >> rules[i].second;
	while (q --) {
		result = 0;
		cin >> s1 >> s2;
		if (s1.length() != s2.length()) {
			cout << 0 << endl;
			continue;
		}
		for (auto rule : rules) {
			if (rule.first.length() > s1.length()) continue;
			result += (replace(s1, rule.first, rule.second) == s2); 
		}
		cout << result << endl;
	}
	return 0;
}
