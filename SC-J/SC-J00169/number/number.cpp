#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e+7;
ll n;
string s;
ll ans[N];

bool cmp(ll a, ll b) {
	if(a > b) return true;
	else return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size(); ++i) {
		if(s[i] == '0' or s[i] == '1' or s[i] == '2' or s[i] == '3'or s[i] == '4'or s[i] == '5'or s[i] == '6'or s[i] == '7'or s[i] == '8'or s[i] == '9') {
			n++;
			ans[n] = s[i] - '0';
		}
	}
	sort(ans + 1, ans + n + 1, cmp);
	for(int i = 1;i <= n; ++i) {
		cout << ans[i];
	}
	
	return 0;
}