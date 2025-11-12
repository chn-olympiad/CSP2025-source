#include <iostream>
#include <algorithm>
using namespace std;
const int L = 1e6+5;
string s;
char a[L];
int p;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0;i < s.length();i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++p] = s[i];
	sort(a+1, a+p+1, greater<int>());
	for (int i = 1;i <= p;i++)
		cout << a[i];
	return 0;
}
