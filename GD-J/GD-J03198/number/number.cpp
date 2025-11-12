#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int num[N];
void solve() {
	string s;
	cin >> s;
	int idx = 0;
	for (auto &c : s) {
		if ('0' <= c && c <= '9') {
			num[++ idx] = c - '0';
		}
	}
	sort(num + 1, num + idx + 1);
	if (num[idx] == 0) cout << 0;
	else for (int i = idx; i; i --) cout << num[i];
	return ;
}
int main(void) {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(0);
	cout.tie(nullptr) -> sync_with_stdio(0);
	solve();
	return 0;
} 
