#include <bits/stdc++.h>
using namespace std;
string s;
int m[20];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			m[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < m[i]; j++)
			cout << i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
