#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[1000005];

ll tong[15], n;

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> (s+1);
	n = strlen(s+1);
	
	for (int i = 1; i <= n; i ++)
		if ('0' <= s[i] && s[i] <= '9')
			tong[s[i]-'0'] ++;
	
	for (int i = 9; i >= 0; i --)
		for (int j = 1; j <= tong[i]; j ++)
			cout << i;
	return 0;
}
