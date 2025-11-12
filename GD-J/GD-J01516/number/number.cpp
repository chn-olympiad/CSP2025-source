#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], len, k = 0;
string s;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for(int i = 0; i < len; i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
		{
			a[++k] = s[i] - '0';
		}
	}
	sort(a + 1, a + k + 1);
	if(a[k] == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = k; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
