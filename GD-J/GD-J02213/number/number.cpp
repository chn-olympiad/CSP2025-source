#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int a[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[cnt++] = s[i] - '0';
		}
	}
	
	sort(a, a + cnt, greater<int>());
	for (int i = 0; i < cnt; i++) {
		cout << a[i];
	}
	
	return 0;
}
