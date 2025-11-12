#include <iostream>
#include <string>
using namespace std;

string s;
int t[128];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> s;
	for (const char &c:s) t[c]++;
	for (char i='9'; i>='0'; --i) {
		for (int j=1; j<=t[i]; ++j) {
			cout << i;
		}
	}
	return 0;
}
