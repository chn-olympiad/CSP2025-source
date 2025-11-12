#include<bits/stdc++.h>
using namespace std;
string s;
string ans="";
int mp[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			int n = s[i]-'0';
			mp[n]++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		if(mp[i]) {
			while(mp[i]--) {
				ans += i+'0'; 
			}
		}
	}
	cout << ans;
	return 0;
}

