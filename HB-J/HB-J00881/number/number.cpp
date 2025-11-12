#include <bits/stdc++.h>

using namespace std;

long long a = 1;
char s[1100000],s2[1100000];

int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	scanf ("%s",s + 1);
	for (int i = 1;i <= int(strlen (s + 1));i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			s2[a] = s[i];
			a++;
		}
	}	
	for (int i = 1;i <= int(strlen (s2 + 1));i++)
	{
		for (int h = i;h <= int(strlen (s2 + 1));h++)
		{
			if (s2[h] > s2[i])
			{
				char d = s2[i];
				s2[i] = s2[h];
				s2[h] = d;
			}
		}
	}
	for (int i = 1;i <= int (strlen (s2 + 1));i++) printf ("%c",s2[i]);
	return 0;
}
