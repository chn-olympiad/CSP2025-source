#include <bits/stdc++.h>
using namespace std;
char a[1000005];
string s;
int cnt = 0;
int main()
{
	cin >> s;
	for(int i = 1;i <= s.length();i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[i] = s[i];
			cnt++;
		}
	}
	sort(a + 1,a + 1 + s.length());
	for(int i = s.length();i >= s.length() - cnt;i--)
	{
		cout << a[i];
	}
	return 0;
}
