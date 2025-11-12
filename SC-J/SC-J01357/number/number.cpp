#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

char s[maxn];

int buc[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (s + 1);
	int len = strlen(s + 1);
	for(int i = 1; i <= len; i++)
		if('0' <= s[i] && s[i] <= '9') buc[s[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		for(int j = 1; j <= buc[i]; j++)
			cout << i;
	return 0;
}