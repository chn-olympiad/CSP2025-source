#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;

int num[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			num[++cnt] = s[i] - '0';
		}
	}
	sort(num + 1, num + cnt + 1);
	for(int i = cnt; i >= 1; i--) cout << num[i];
	return 0;
}
