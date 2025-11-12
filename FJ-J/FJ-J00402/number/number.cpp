#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin >> s;
	char lct[10] = {0};
	string ans;
	string s1;
	int cnt[10] = {0};
	for(int i = 0;i < s.length();i++) {
		if('0' <= s[i] && '9' >= s[i]) {
			cnt[s[i]-'0']++;
		}
	}
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= cnt[i];j++) {
			cout << i;
		}
	}
	return 0;
}
