/* CSP 2025 RP++
T1
10 Min Yu ji 100 */ 
#include <bits/stdc++.h> 
using namespace std;
string str, ans;
int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	cin >> str;
	for (char ch : str) if (isdigit(ch)) ans += ch;
	sort(ans.begin(), ans.end(), greater<char>()), cout << ans << endl; 
	return 0;
}
