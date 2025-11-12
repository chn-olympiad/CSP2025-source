/*
so? CSP-J 红橙黄黄?
666
来luogu找我：1023865
*/
#include <iostream>

using namespace std;

int cnt[15];
bool flag = false;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	char ch;
	while (cin >> ch)
		if ('0' <= ch && ch <= '9')
			cnt[ch - '0']++;
	for (int i = 1; i <= 9; i++)
		flag = flag || bool(cnt[i]);
	if (!flag) {
		cout << "0" << endl;
	} else {
		for (int i = 9; ~i; i--)
			while (cnt[i] --> 0)
				cout << i;
		cout << endl;
	}
	return 0;
}
