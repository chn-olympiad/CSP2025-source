#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,w,s;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    w = m * n + 1;
    int a[w];
    for(int i = 1;i < w;i++)
    {
		cin >> a[i];
	}
	s = a[1];
	sort(a + 1,a + w);
	int g = w / 2;
	for(int i = 1;i <= g;i++)
	{
		int k = a[i];
		a[i] = a[w - i];
		a[w - i] = k;
	}
	for(int i = 1;i < w;i++)
	{
		if(a[i] == s)
		{
			s = i;
			break;
		}
	}
	if(s % (2 * n) == 0)
	{
		m = s / n;
		n = 1;
	}
	else if(s % (2 * n) < n)
	{
		m = s / n + 1;
		n = s % n;
	}
	else if(s % (2 * n) == n)
	{
		m = s / n;
	}
	else
	{
		m = s / n + 1;
		n = n - (s % n) + 1;
	}
	cout << m << " " << n;
    return 0;
}
