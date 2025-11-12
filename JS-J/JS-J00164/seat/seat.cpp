#include <bits/stdc++.h>
using namespace std;
const int maxn = 10 * 10 + 10;
int a[maxn];
int n,m;
bool cmp(int b1,int b2)
{
	return b1 > b2;
}
int ef(int x)
{
	int left = 2,right = n * m;
	while(left < right)
	{
		int des = (left + right) / 2;
		if(a[des] < x)
		{
			left = des;
		}
		else if(a[des] > x)
		{
			right = des;
		}
		else if(a[des] == x)
		{
			left = des;
			break;
		}
	}
	return left;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int xm;
	scanf("%d %d",&n,&m);
	scanf("%d",&xm);
	for(int i = 2;i <= n * m;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a + 2,a + n * m,cmp);
	int wz = ef(xm);
	if(wz <= n)
	{
		printf("1 %d",wz);
	}
	else{
		printf("%d",(wz - 1) / n + 1);
		if(((wz - 1) / n + 1) % 2 == 1)
		{
			if(wz % n == 0) printf("%d",n);
			else printf("%d",wz % n);
		}
		else
		{
			printf("%d",n - (wz - 1) % n);
		}
	}
	return 0;
}
