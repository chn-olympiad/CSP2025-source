#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
char s[MAXN];
int num[10], k=0;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", &s);
	for (int i=0; i<MAXN; i++)
	{
		if (s[i]>='0' && s[i]<='9')
			num[s[i]-'0']++;
	}
	for (int i=9; i>=0; i--)
	{
		for (int j=0; j<num[i]; j++)
			printf("%d", i);
	}
	return 0;
}