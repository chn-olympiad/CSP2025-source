#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			v.push_back(s[i] - '0');
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i : v) {
		cout << i;
	}
	cout << endl;
	return 0;
}
