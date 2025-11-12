#include <bits/stdc++.h>

using namespace std;

string s;
int a[10], cnt;
__int128 ans;

int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	
	cin >> s;
	int lens = s.length();
	
	for (int i = 0; i < lens; i ++) if (s[i] - '0' < 10 && s[i] - '0' >= 0) {a[s[i] - '0'] ++;}
	
	for (int i = 9; i >= 0; i --) {
		if (a[i] != 0) {
			while (a[i] --) cout << i;
		}
	}
	
	return 0;
}
/*
290es1q0
99998888887777766666655555544444433332111000000000
99998888887777766666655555544444433332111000000000
99998888887777766666655555544444433332111000000000
*/
