#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],num;
bool a1(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n * m;i++) scanf("%d",&a[i]);
	num = a[1];
	sort(a + 1,a + n * m + 1,a1);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == num)
		{
			num = i;
			break;
		}
	}
	if((num - 1) % (2 * n) < n) printf("%d %d",(num + n - 1) / n,(num % (2 * n)));
	else printf("%d %d",(num + n - 1) / n,(2 * n + 1) - ((num - 1) % (2 * n) + 1));
	return 0;
}
