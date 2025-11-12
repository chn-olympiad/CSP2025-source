#include <bits/stdc++.h>
using namespace std;
string s1;
int s2[20], cnt;
bool f;
int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	cin >> s1;	
	for (int i = 0; i < int (s1.size ()); ++i)
	{
		if (s1[i] >= '0' && s1[i] <= '9')
		{
			s2[s1[i] - '0']++; 
		}
	}
	for (int i = 9; i >= 1; --i)
	{
		for (int j = 1; j <= s2[i]; ++j)
		{
			cout << i;
			f = 1;
		}
	}
	if (f)
	{
		for (int i = 1; i <= s2[0]; ++i)
		{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
} 
