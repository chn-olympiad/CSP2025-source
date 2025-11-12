#include <bits/stdc++.h>
using namespace std;

int a[500010] = {0};
int qian[500010] = {0};

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		qian[i] = qian[i - 1] ^ a[i];
	}
	int s = 1;
	long long g = 0;
	for (int r = 1;r <= n;r++)
	{
		for (int l = s;l <= r;l++)
		{
			if ((qian[r] ^ qian[l - 1]) == k)
			{
				//printf("%d %d\n",l,r);
				g += 1;
				s = r + 1;
				break;
			}
		}
	}
	printf("%lld",g);
	return 0;
}
