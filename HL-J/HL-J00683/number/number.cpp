#include <bits/stdc++.h>
using namespace std;
char s[10000001];//flt
int a[10000001];//flt
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int lens = strlen(s);
	int p = 0;
	for (int i = 0;i < lens;i++)
	{
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			a[p] = s[i] - '0';
			++p;
		}
	}
	sort(a,a+p);
	for (int i = p-1;i >= 0;i--)
	{
	printf("%d",a[i]);
	}
	return 0;
}
