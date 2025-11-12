#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (auto i : s) {
		if ('0' <= i && i <= '9') {
			a.push_back(i - '0');
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (auto i : a) {
		cout << i;
	}
	cout << endl;
	return 0;
}
// luogu uid: 1277793
// 💯
