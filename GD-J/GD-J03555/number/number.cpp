#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 20;

string s;
int b[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	int len = s.size();
	
	for(int i = 0; i < len; ++ i) {
		if(s[i] >= '0' && s[i] <= '9') {
			b[s[i] - 48] ++;
		}
	}	
	
	bool f = 0;
	
	for(int i = 9; i > 0; -- i) {
		if(b[i]) {
			f = 1;
			break;
		}
	}
	
	if(f == 0) {
		cout << "0";
		return 0;
	}
	
	for(int i = 9; i >= 0; -- i) {
		for(int j = 1; j <= b[i]; j ++) {
			cout << char(i + 48);
		}
	}
	return 0;	
} 
