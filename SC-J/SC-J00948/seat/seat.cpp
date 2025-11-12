#include <bits/stdc++.h>
using namespace std;
int a[200], r, n, m, pos;
bool cmp(int x, int y)
{
	return x > y;
}
int ansx, ansy;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int s = n * m;
	for(int i = 1;i <= s;i ++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + 1 + s, cmp);
	for(int i = 1;i <= s;i ++)
		if(a[i] == r)
		{
			pos = i;
			break;
		}
	if(n == 1)
		cout << 1 << " " << pos;
	else if(m == 1)
	    cout << pos << " " << 1;
	else
	{
	    if(pos % n == 0)
	    {
		    int p = pos / n;
		    ansx = p;
		    if(p % 2 == 0)
		    	ansy = 1;
    		else
	    	    ansy = n;
	    }
	    else
    	{
	    	int p = pos / n + 1, q = pos % n;
		    ansx = p;
    		if(p % 2 == 1)
	    	    ansy = q;
		    else
		        ansy = n - q + 1;
	    }
	    cout << ansx << " " << ansy;
	}
	return 0;
}