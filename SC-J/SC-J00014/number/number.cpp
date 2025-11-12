#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define res(i, a, n) for(ll i = a; i <= n; i++)
#define rep(i, a, n) for(ll i = a; i >= n; i--)
const int N = 1e5+5;
string s, ans;
ll t[15];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    cin >> s;
    res(i, 0, s.size()-1) if(s[i] >= '0' && s[i] <= '9') t[s[i]-'0']++;
    rep(i, 9, 0) while(t[i]--) ans += (i+'0');
	cout << ans;
	return 0;
} 