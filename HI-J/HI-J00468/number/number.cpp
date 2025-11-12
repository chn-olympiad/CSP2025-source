#include<bits/stdc++.h>
using namespace std;
char c[1000005];
long num[15];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", &c);
	for(int i = 0; ; i ++)
	{
		if(c[i] == '\0')break;
		if(c[i] >= '0' && c[i] <= '9')
		{
			num[c[i] - '0'] ++;
		}
	}
	for(int i = 9; i >= 0; i --)
	{
		if(num[i])
		{
			for(int j = 1; j <= num[i]; j ++)
			{
				printf("%d", i);
			}
		}
	}
	cout << endl;
	return 0;
}
