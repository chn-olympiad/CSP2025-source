#include <bits/stdc++.h>
#define GXOI good
using namespace std;
const int N = 1e6 + 5;
string s;
char a[N];
int top;
bool cmp (char x, char y) {
	return x > y;
}
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < (int)s.size (); i ++)
		if (s[i] >= '0' && s[i] <= '9') {
			top ++;
			a[top] = s[i];
		}
	sort (a + 1, a + top + 1, cmp);
	for (int i = 1; i <= top; i ++)
		cout << a[i];
	return 0;
}
