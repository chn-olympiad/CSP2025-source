#include <bits/stdc++.h>

using namespace std;

string s;
int a[1314520];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size(), cnt = 0;
	for (int i = 0; i < n; i++)
		if ('0' <= s[i] && s[i] <= '9')
			a[++cnt] = s[i] - '0';
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i; i--)
		printf("%d", a[i]);
	return 0;
}