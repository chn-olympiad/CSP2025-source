#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[105];
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n * m;i++)
	{
		scanf("%d",&a[i]);
	}
	int r = a[1];
	sort(a + 1,a + n * m + 1);
	for (int i = 1;i <= n * m;i++)
	{
		if (a[i] == r) {r = n * m - i + 1;break;}
	}
	int h,l;
	if (!(r / m))
	{
		l = 1;h = r;
	}
	else if ((r / m) % 2)
	{
		l = 1 + r / m;h = r - (l - 1) * (l - 1);
	}
	else
	{
		l = 1 + r / m;h = r % n;
		if (!h) h = n;
	}
	printf("%d %d",l,h);
	return 0;
}
