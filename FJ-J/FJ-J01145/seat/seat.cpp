#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n,m;
int a[N];
bool cmp(int p,int q)
{
	return p > q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	int s1 = a[1],s = 1;
	for(int i = 2;i <= n * m;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n * m + 1,cmp);
	while(s1 != a[s])
	{
		s++;
	}
	int x,y = s / n;
	if(s % n != 0) y++;
	if(y % 2 != 0)
	{
		x = s % n;
		if(s % n == 0)
		{
			x = n;
		}
	}
	else
	{
		x = n - s % n + 1;
		if(s % n == 0)
		{
			x = 1;
		}
	}
	cout << y << " " << x;
	return 0;
}
