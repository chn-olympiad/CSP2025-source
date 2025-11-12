#include<bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f, g, h, p, q;
int notzero;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string ans = "";
	for (int i = 0; i < s.length(); i ++) {
		if (s[i] == '0') a ++;
		else if (s[i] == '1') b ++;
		else if (s[i] == '2') c ++;
		else if (s[i] == '3') d ++;
		else if (s[i] == '4') e ++;
		else if (s[i] == '5') f ++;
		else if (s[i] == '6') g ++;
		else if (s[i] == '7') h ++;
		else if (s[i] == '8') p ++;
		else if (s[i] == '9') q ++;
	}
	notzero = b + c + d + e + f + g + h + p + q;
	for (int i = 0; i < q; i ++) ans += "9";
	for (int i = 0; i < p; i ++) ans += "8";
	for (int i = 0; i < h; i ++) ans += "7";
	for (int i = 0; i < g; i ++) ans += "6";
	for (int i = 0; i < f; i ++) ans += "5";
	for (int i = 0; i < e; i ++) ans += "4";
	for (int i = 0; i < d; i ++) ans += "3";
	for (int i = 0; i < c; i ++) ans += "2";
	for (int i = 0; i < b; i ++) ans += "1";
	for (int i = 0; i < a; i ++) ans += "0";
	if (!notzero) ans = "0";
	cout << ans << "\n"; 
	return 0;
}