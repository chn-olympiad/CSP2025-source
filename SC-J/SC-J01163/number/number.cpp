#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
char c[N];
int cnt;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++) {
		if(isdigit(s[i])) c[++cnt] = s[i];
	}
	sort(c + 1, c + cnt + 1, greater<char>());
	for(int i = 1; i <= cnt; i++) cout << c[i];
	return 0;
}
