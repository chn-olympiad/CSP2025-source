#include <bits/stdc++.h>

using namespace std;

int t[11];

int main() {
	freopen("number.in", "r", stdin); 
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s ;
	
	for(int i = 0;i < s.size();i++) {
		if(!(s[i] >= '0' && s[i] <= '9')) continue;
		int num = s[i] - '0';
		t[num]++;
	}
	
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= t[i];j++) {
			cout << i ;
		}
	}
	
	
	
	return 0;
} 
