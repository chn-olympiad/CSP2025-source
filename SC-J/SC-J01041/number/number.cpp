#include<bits/stdc++.h>

using namespace std;

int a[1000005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	int id = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++id] = s[i] - '0';
		}
	}
	sort(a + 1, a + id + 1);
	for (int i = id; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
