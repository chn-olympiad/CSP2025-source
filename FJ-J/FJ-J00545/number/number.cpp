#include <bits/stdc++.h>

using namespace std;

string s;
int a[1000010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	
	int n = s.size();
	for(int i = 0; i < n; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] += s[i] - '0' + 1;
		}
	}
	
	sort (a, a + n, cmp);
	
	for(int i = 0; i < n; i ++) {
		if (a[i]) {
			cout << a[i] - 1;
		}
	}
	
	return 0;
}
