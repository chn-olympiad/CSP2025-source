#include <bits/stdc++.h>
typedef long long lng;
using namespace std;
const lng man = 2e5 + 5;
int c[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for(char &ch : s)
	{
		if(!isdigit(ch)) continue;
		c[ch - '0']++;
	}
	for(int i = 9; i >= 0; --i)
		while(c[i]--) cout << i;
	cout << '\n';
	return 0;
}