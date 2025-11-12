#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

std::string str;
std::string cnt[10];

int main() {
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);
	
	cin >> str;
	
	for(char ch : str) {
		
		if(ch >= '0' && ch <= '9') {
			
			cnt[ch - '0'] += ch;
		}
	}
	
	for(int i = 9; i >= 0; --i) {
		
		cout << cnt[i];
	}
	
	return 0;
}
