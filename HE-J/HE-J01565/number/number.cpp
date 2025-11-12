#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define unsigned long long ull;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c = 'u';
	while(c != '\n')
	{
		scanf("%c",&c);
		if(c >= '0' && c <= '9')
			a[c - '0'] ++;
	}
	for(int i = 9;i >= 0;i --)
	{
		for(int j = 1;j <= a[i];j ++)
			printf("%d",i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
