#include<bits/stdc++.h>
using namespace std;
int n, m, tot, a[104], h, s, c, r, w;
int bj(int a , int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	tot = n * m;
	for(int i = 1; i <= tot; i++)
	{
		cin >> a[i];
		
	}
	s = a[1];
	sort(a+1,a+tot+1,bj);
	for(int i = 1; i <= tot; i++)
	{
		if(s == a[i])
		{
			h = i;
			break;
		}
	}
	c = (h + n -1) / n;
	w = h - (c - 1) * n;
	if(c % 2 == 0)
	{
		r = n + 1 - w;
	}
	else
	{
		r = w;
	}
	cout << c << " " << r << endl;
	return 0;
}
