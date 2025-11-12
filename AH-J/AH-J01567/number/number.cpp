#include <bits/stdc++.h>
using namespace std;
long long t[10] = {0,0,0,0,0,0,0,0,0,0};
char s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while (cin >> s)
	{
		if ('0' <= s && s <= '9')
		{
			t[(s - '0')]++;
		}
	}
	for (long long i = 9;i >= 0;i--)
	{
		for (long long j = 1;j <= t[i];j++)
		{
			cout << i;
		}
	}
}
