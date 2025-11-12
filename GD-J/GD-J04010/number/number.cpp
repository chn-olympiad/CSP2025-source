#include <iostream>
#include <string> 
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MAXN = 1e6+5;
LL n, num[15];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s;
	for (LL i = 0; i<(LL)s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			num[s[i]-'0']++, n++;
	if (n == 1 && num[0]) num[0] = 1;
	for (LL i = 9; i>=0; i--)
		while (num[i]--) cout << i; 
	return 0;
} 
