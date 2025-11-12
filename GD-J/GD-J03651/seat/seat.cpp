#include <bits/stdc++.h>
using namespace std;
int n, m, a, tmp, c, r, num = 1;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 1; i < n * m; i++)
	{
		cin>>tmp;
		if(tmp > a) num++;
	}
	c = ceil(num * 1.0 / n);
	if(c % 2 == 1)
		r = num - (c - 1) * n;
	else
		r = n - (num - (c - 1) * n) + 1;
	cout<<c<<' '<<r;
	return 0;
}
