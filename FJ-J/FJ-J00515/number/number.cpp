#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int a[1000010],n[1000010],num=0,x;
	cin >> s;
	for (int i=0;i<s.length();i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			n[num] = s[i] - '0';
			num++;
		}
	}
	sort(n,n+num);
	for (int i=num-1;i>=0;i--)
	{
		cout << n[i];
	}
	return 0;
}
