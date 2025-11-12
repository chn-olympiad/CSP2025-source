#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000005],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int sl = s.length();
	for (int i = 0;i < sl;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = (int)(s[i] - '0');
	}
	sort(a + 1,a + cnt + 1);
	for (int i = cnt;i >= 1;i--)
		cout << a[i];
}
