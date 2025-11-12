#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int cnt;
int num[N];
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i ++ ) {
		if(s[i] >= '0' && s[i] <= '9') {
			num[ ++ cnt] = s[i] - 48;
		}
	}
//	cout << cnt << endl;
	sort(num, num + cnt + 1);
	for(int i = cnt;i >= 1;i -- ) {
		cout << num[i];
	}
	return 0;
}
