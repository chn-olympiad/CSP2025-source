#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
string str;
int cnt[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> str;
	int len = str.size(), out = 0;
	for (int i = 0; i < len; i++) if (str[i] >= '0' && str[i] <= '9') cnt[str[i] - '0']++;
	for (int i = 9; i > 0; i--)
		if (cnt[i]) {
			out = 1;
			for (int j = 1; j <= cnt[i]; j++) cout << i;
		}
	if (out) for (int j = 1; j <= cnt[0]; j++) cout << 0;
	else cout << 0;
	cout << '\n';
	return 0;
}