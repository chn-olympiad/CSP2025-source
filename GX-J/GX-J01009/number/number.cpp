#include <iostream>
#include <algorithm>
using namespace std;
int pos;
short a[1000005];
string s;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < int(s.length()); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			pos++;
			a[pos] = s[i] - 48;
		}
	}
	sort(a + 1, a + pos + 1);
	for (int i = pos; i; i--)
	{
		cout << a[i];
	} 
	return 0;
}
