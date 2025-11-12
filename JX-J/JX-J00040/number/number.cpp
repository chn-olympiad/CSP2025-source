#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
string s;
int cnt[12];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a=s.length();
	for (int i=0;i<a;i++)
	{
		if (0<=s[i]-'0' && s[i]-'0'<=9)
		{
			cnt[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=cnt[i];j++)
		{
			cout <<i;
		}
	}
	return 0;
}
