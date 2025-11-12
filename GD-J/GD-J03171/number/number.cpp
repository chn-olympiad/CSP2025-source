#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b){
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, ans = "";
	cin >> s;
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < s.size(); i++) if (s[i] <= '9' && s[i] >= '0') ans += s[i];
	cout << ans;
	return 0;
} 
