#include <iostream>
#include <map>
using namespace std;

string s;
map<int, long long> mp;
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char ch : s) {
		if (ch >= '0' && ch <= '9') mp[(ch - '0')]++;
	}
	for (int i = 9;i >= 0;i--) {
		while (mp[i]) {
			if (i) flag = true;
			if (!i && !flag) {
				cout << "0\n";
				return 0;
			}
			cout << i;
			mp[i]--;
		}
	}
	return 0;
}
