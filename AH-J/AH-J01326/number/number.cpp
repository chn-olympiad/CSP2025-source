#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string s;
int a[N], n;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++) 
		if(isdigit(s[i]))
			a[++n] = s[i] - '0';
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--)
		cout << a[i];
	cout << endl;
	return 0;
}
