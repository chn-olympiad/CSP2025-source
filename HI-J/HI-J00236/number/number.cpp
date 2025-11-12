#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6 + 5;
int num[N], j;
bool cmp (int x, int y) {
	return x > y;
}
int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[j] = s[i] - '0';
			j++;
		}
	}
	sort(num, num + j, cmp);
	for (int i = 0; i < j; i++) {
		cout << num[i];
	}
	return 0;
}
