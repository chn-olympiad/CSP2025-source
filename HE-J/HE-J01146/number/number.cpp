#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
string s;
int cnt, a[maxn];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')
		{
			cnt++;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + cnt);
	for(int i = cnt; i >= 1; i--)
		cout << a[i];
	return 0;
}
