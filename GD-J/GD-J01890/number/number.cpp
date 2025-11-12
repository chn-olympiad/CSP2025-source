#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005] , len;
bool cmp (long long x , long long y)
{
	return x > y;
}
int main ()
{
	
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
	cin >> s;
	for (int i = 0;i < s.size();i ++)
	{
		if (s[i] >='0' && s[i] <= '9')
		{
			len ++;
			a[len] = s[i] - '0';
		}
	}
	sort (a + 1 , a + len + 1 , cmp);
	for (int i = 1;i <= len;i ++)
	{
		printf ("%lld" , a[i]);
	}
	return 0;
}
