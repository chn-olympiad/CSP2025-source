#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int a[1000010];
int main() {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	int k = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' &&s[i] <= '9')
			a[k++] = s[i] - 48;
	}
	sort (a, a + k + 1);
	for (int i = k; i > 0; i--) cout << a[i];
	return 0;
}
