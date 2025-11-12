#include <iostream>
#include <string> 

using namespace std;

int num[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	for (const char& n : str) {
		if (n <= '9' && n >= '0') num[n-'0']++;
	}
	
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= num[i]; j++) {
			cout << i;
		}
	}
	
	return 0;
} 
