#include<bits/stdc++.h>

using namespace std;

string s;
long long cnt[105];
bool flag = true;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			cnt[s[i] - '0']++;
		}
	}
	for(int i = 9;i >= 1;i--) {
		if(cnt[i]) flag = false;
	}
	if(flag == true) {
		cout << 0;
		return 0;
	}
	for(int i = 9;i >= 0;i--) {
		while(cnt[i]) {
			cout << i;
			cnt[i]--;
		}
	}
	return 0;
} 
