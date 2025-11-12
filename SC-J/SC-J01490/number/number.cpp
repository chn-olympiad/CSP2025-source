#include<bits/stdc++.h>
using namespace std;


string s;
int a[1000010];
long long cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (long long i = 0; i < s.size(); ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt++;
			a[cnt] = int(s[i] - '0');
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	if (a[1] == 0) {
		cout << "0";
	} else {
		for (long long i = 1; i <= cnt; ++i) {
			cout << a[i];
		}
	}

	return 0;
}