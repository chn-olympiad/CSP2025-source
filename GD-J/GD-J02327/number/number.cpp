#include <bits/stdc++.h>
using namespace std;
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	a = getchar();
	while (a != '\n')
	{
		if (a >= '0' && a <= '9')
		{
			num[a-'0']++;
		}
		a = getchar();
	}
	for (int i = 9;i >= 0;i--)
	{
		for (int j = 0;j < num[i];j++)
			cout << i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
