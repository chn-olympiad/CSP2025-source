#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[1000005],p = 1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9') {a[p] = int(s[i] - '0');p++;}
	}
	sort(a + 1,a + p);
	for (int i = p - 1;i >= 1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}
