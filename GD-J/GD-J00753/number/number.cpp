#include<bits/stdc++.h>
using namespace std;

int s[100];
char m[100004];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	memset(s, 0, sizeof s);
	for (int i = 0; i < 100004; i++) {
		m[i] = 'z';
	}
	
	scanf("%s", &m);
	for (int i = 0; i < 100004; i++) {
		if ('0' <= m[i] && m[i] <= '9') {
			s[m[i] - '0'] += 1;
		}
	}
	
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < s[i]; j++) {
			cout << i;
		}
	}
	
	return 0;
}
