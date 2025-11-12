#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int t[20];
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i++) {
		if('0' <= s[i] && s[i] <= '9') {
		    t[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--) {
		while(t[i]) {
			cout << i;
			t[i]--;
		}
	}
	return 0;
}
