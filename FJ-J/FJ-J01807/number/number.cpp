#include <bits/stdc++.h>
using namespace std;

int cnt[15];
char a;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while(1)
	{
		a = getchar();
		if(a == '\n') break;
		if(a >= '0' && a <= '9')
		{
			cnt[(int)(a - '0')]++;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		while(cnt[i]--)
		{
			putchar(i + 48);
		}
	}
	putchar('\n');
	return 0;
}
