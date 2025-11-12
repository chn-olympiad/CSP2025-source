#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1, b, c, r;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    a1 = a[1];
    sort(a + 1, a + n * m + 1);
    for(int i = n * m; i >= 1; i--)
    {
        if(a[i] == a1)
        {
            b = n * m - i + 1;
            break;
        }
    }
    if(b % n == 0) c = b / n;
    else c = b / n + 1;
    if(c % 2 == 1)
    {
        if(b % n == 0) r = n;
        else r = b % n;
    }
    else
    {
        if(b % n == 0) r = 1;
        else r = n - b % n + 1;
    }
    cout << c << ' ' << r;
	return 0;
}
