#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int a = 0;
    int t[1000005];
    int b[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cin >> a;
    int i = 0;
    while (true)
    {
    	if (a == 0)
    	{
	    	t[i] = a % 10;
	    	a = (a-(a % 10)) / 10;
	    	break;
		}
    	t[i] = a % 10;
    	a = (a-(a % 10)) / 10;
    	i++;
	}
	for (int j = 0; j <= i; j++)
	{
		b[9 - t[j]]++;
	}
	for (int j = 0; j <= 9; j++)
	{
		for (int y = 0; y <= b[j]; y++)
		{
			cout << 9 - j;
		}
	}
	return 0;
}
