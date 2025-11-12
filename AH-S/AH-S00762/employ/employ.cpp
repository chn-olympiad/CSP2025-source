#include <bits/stdc++.h>
#define ll long long
const int mod = 998244353;
using namespace std;
struct node {
	int num, pat;
};
bool cmp (node u, node v) {
	return u.num < v.num;
}
node p[505];
int n, m, cnt = 0, ans = 0;
string str;
ll frac (int n) {
	ll t = 1;
	for (int i = n; i >= 2; -- i) t = (t * i) % mod;
	return t;
}
bool check () {
	int cur = 0, num = 0;
	for (int i = 1; i <= n; ++ i) {
		if (cur >= p[i].pat || str[i] == '0') ++ cur;
		else ++ num;
	}
	return (num >= m);
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	bool flg = true;
	cin >> n >> m;
	cin >> str;
	str = " " + str;
	for (int i = 1; i <= n; ++ i) {
		cin >> p[i].pat;
		p[i].num = i;
		if (str[i] == '0') flg = false;
		if (!p[i].pat) ++ cnt;
	}
	//if (flg) cout << frac (cnt) * frac (n - cnt) % mod;
	//else {
		do {
			//for (int i = 1; i <= n; ++ i) cout << p[i].num;
			if (check ()) {
				ans = (ans + 1) % mod;
				
			}
		} while (next_permutation (p + 1, p + n + 1, cmp));
		cout << ans;
	//}
	return 0;
}
