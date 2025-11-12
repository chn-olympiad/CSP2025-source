#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp ( int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	if (s.size() == 1) {
		if(s >= "0" && s <= "9") {
			cout << s;
			return 0;
		}
	}
	sort (s.begin(), s.end(), cmp);
	for (int i = 0; i < s.size(); i ++) {
		if(s[i] >= 48 && s[i] <= 57) cout << s[i];
	}
	return 0;
}
