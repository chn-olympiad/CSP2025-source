#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int cnt = 0;
string s;
char a[1000010];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);	
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[cnt++] = s[i]; 
		}
	}
	for(int i = 0; i < strlen(a) - 1; i++)
	{
		for(int j = i + 1; j < strlen(a); j++)
		{
			char sw;
			if(a[j] > a[i])
			{
				sw = a[j];
				a[j] = a[i];
				a[i] = sw;
			}
		}
	}
	for(int i = 0; i < strlen(a); i++)
	{
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
