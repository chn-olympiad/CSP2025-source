#include <bits/stdc++.h>

using namespace std;

int cmp(char a, char b) {
	return a > b;
}

const int N = 1e6 + 10;

char n[N];
int k = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			n[k++] = s[i];
		}
	}
	sort(n, n + k, cmp);
	for(int i = 0; i < k; i++) {
		cout << n[i];
	}
	return 0;
} 
