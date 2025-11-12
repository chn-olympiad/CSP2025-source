#include<bits/stdc++.h>
using namespace std;
const int max_n = 1e6 + 5;

int a[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	
	for (int i = 9; i >= 0; i--) {
		if (!a[i])
			continue;
		
		for (int j = 1; j <= a[i]; j++)
			printf("%d", i);
	}
	
	return 0;
}