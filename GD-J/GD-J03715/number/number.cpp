#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string s;
int a[1000000],cnt;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i <= s.size()-1;i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			a[++cnt] = s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for (int i = 1;i <= cnt;i++)
	{
		cout << a[i];
	}
	return 0;
}
