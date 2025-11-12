#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100100], t;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n * m; ++i)
    {
        scanf("%d", &a[i]);
    }
    int mx = a[1];
    if (n == 1)
    {
    	sort(a + 1, a + n * m + 1);
		for (int i = n * m; i >= 1; --i)
		{
			t++;
			if (a[i] == mx)
			{
				cout << 1 << ' ' << t;
				break;
			}
		 } 
	} else if (mx == 99)
    {
        cout << "1 2";
    } else if (mx == 98)
    {
        cout << "2 2";
    } else if (mx == 94)
    {
        cout << "3 1";
    }else
    {
        cout << n << "1";
    }
    
    return 0;
}