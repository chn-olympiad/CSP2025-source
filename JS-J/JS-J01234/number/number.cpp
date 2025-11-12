#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int a[N], num = 0;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for(int i = 0; i < N; ++i) a[i] = 0;
	for(int i = 0; i < (int) s.size(); ++i) {
		if('0' <= s[i] && s[i] <= '9') {
			a[num] = s[i] - '0';
			num++;
		}
	}
	sort(a, a + num, greater<int>());
	for(int i = 0; i < num; ++i) cout << a[i];
	return 0;
}
