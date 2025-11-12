#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
string s;
int ans[N], cnt;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (isdigit(s[i])) {
			cnt ++;
			ans[cnt] = s[i] - '0';
		}
	}
	sort(ans + 1, ans + 1 + cnt);
	for (int i = cnt; i >= 1; i --) {
		cout << ans[i];
	}
	return 0;
}
