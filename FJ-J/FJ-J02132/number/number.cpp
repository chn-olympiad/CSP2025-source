#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
string s;
int num[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.length(), tot = 0;
	for (int i = 0;i < len;i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[++tot] = s[i] - '0';
		}
	}
	sort(num + 1, num + tot + 1);
	for (int i = tot;i >= 1;i--) {
		cout << num[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
