#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	int choose[5010];
	long long s = 0;
	for(long long i=7; i<=(1<<n); i++)
	{
		long long x = i;
		int t = 0;
		int m = 0;
		while(x > 0)
		{
			choose[++t] = x%2;
			if(x%2) m++;
			x/=2;
		}
		if(m < 3) continue;
		long long sum = 0;
		int maxl = 0;
		for(int j=1; j<=n; j++)
		{
			sum += a[j]*choose[j];
			maxl = max(maxl, a[j]*choose[j]);
		}
		if(sum <= 2*maxl) continue;
		s++;
		s %= 998244353;
	}	
	printf("%lld",s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
