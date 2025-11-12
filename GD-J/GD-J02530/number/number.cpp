#include <bits/stdc++.h>
#define csp "number"
using namespace std;
using LL = long long;
string s, ans;
void solve() {
	cin >> s;
	for(char i : s) if(isdigit(i)) ans += i;
	sort(ans.begin(), ans.end(), greater <char> ());
	printf("%s\n", ans.c_str());
}
int main() {
	freopen(csp ".in", "r", stdin);
	freopen(csp ".out", "w", stdout);
//	LL t; scanf("%lld", &t); while(t --)
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
