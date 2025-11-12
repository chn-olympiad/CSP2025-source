#include<iostream>
using namespace std;

int a[100];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if ('0' <= s[i] && '9' >= s[i]) a[int(s[i] - '0')]++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++)
			cout << char(i + '0');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
