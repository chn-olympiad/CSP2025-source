#include <bits/stdc++.h>
using namespace std;

char a[1000001];
int cnt;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len = s.size();
	for (int i=0;i<len;i++)
	{
		if (s[i] == '9')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '8')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '7')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '6')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '5')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '4')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '3')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '2')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '1')
			cout << s[i];
	}
	for (int i=0;i<len;i++)
	{
		if (s[i] == '0')
			cout << s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
