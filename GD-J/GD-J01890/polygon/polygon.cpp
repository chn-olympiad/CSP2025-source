#include <bits/stdc++.h>
using namespace std;
int main ()
{
	
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout);
	srand ((long long)time (0));
	long long k = rand () % 8 + 1;
	for (int i = 1;i <= k;i ++)
	{
		t:
		long long l = rand () % 10;
		if (l == 0) goto t;
		cout << l;
	}
	return 0;
}
