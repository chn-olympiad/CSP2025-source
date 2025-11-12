#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 0;
	int n[s.length()];
	for(int i = 0; i < s.length(); i++) {
		if(s[i] >= 48 && s[i] <= 57) {
			n[j] = s[i] - 48;
			j++;
		}
	}
	sort(n, n + j, cmp);
	for(int i = 0; i < j; i++) {
		cout << n[i];
	}
	return 0;
}
