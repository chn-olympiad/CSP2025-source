#include <bits/stdc++.h>
using namespace std;
    int n, m, a[105], x, e, d, b, c;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> x;
	a[1] = x;
	for(int i = 2; i <= n * m; i++)
	    cin >> a[i];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
	    if(a[i] == x)
	    	b = i;
    if(b == n)
    {
        c = b / n;
        d = b;
    }
    else
    {
	    c = b / n + 1;
	    d = b % n;
	}
	if(c % 2 == 1)
	    e = d;
	else
	    e = n - d + 1;
    cout << c << " " << e;
	return 0;
}
