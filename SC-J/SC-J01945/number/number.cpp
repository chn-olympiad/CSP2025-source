#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
string s;
int a[1000010];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getline(cin, s);
	int cnt = 0;
	int len = s.size();
	for(int i = 0; i < len; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			a[cnt++] = s[i] - '0';
		}
	}
	sort(a, a + cnt, cmp);
	if(a[0] == 0) {
		cout << 0;
		return 0;
	}
	for(int i = 0; i < cnt; i++) {
		cout << a[i];
	}
	return 0;
}