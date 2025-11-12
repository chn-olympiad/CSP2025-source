#include<bits/stdc++.h>
using namespace std;
char a[1000010];
int p = 0;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < int(s.size()); i++) {
		if('0' <= s[i] && s[i] <= '9') {
			a[++p] = s[i];
		}
	}
	sort(a + 1, a + p + 1);
	for(int i = p; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
//  freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
//Luogu: 1327341
//1111111111
