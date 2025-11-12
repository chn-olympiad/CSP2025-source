#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[15], temp=0, i;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	temp=strlen(s);
	for (i=0; i<temp; i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{			
			a[s[i]-'0']++;
		}
	}
	for (i=9; i>=0; i--)
	{
		for (int j=1; j<=a[i]; j++)
		{
			cout << i;
		}
	}
	return 0; 
} 
