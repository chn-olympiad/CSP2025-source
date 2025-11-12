#include <bits/stdc++.h>
using namespace std;

int a[5010] = {0};
int qian[5010] = {0};
long long INF = 998244353;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max_a = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		qian[i] = qian[i - 1] + a[i];
		max_a = max(max_a,a[i]);
	}
	if (n == 3)
	{
		if (qian[3] >= max_a * 2)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	if (max_a == 1)
	{
		printf("%lld",((1 + n - 2) * (n - 2) / 2) % INF);
		return 0;
	}
}
