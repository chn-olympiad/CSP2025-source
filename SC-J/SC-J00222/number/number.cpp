#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a [N] , cur;

int main ()
{
	freopen ("number.in" , "r", stdin);
	freopen ("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int len = s . size ();
	for (int i = 0;i < len;i++)
	{
		if (s [i] >= '0' && s [i] <= '9')
		{
			a [++ cur] = s [i] - '0';
		}
	}
	sort (a + 1 , a + cur + 1);
	for (int i = cur;i >= 1;i--)
	{
		cout << a [i];
	}
	return 0;
}