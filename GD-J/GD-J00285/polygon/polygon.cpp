#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],max_num,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i = 0;i < n;i++)
	{
		scanf("%lld",&a[i]);
		if(max_num < a[i]) max_num = a[i];
		sum += a[i];
	}
	if(sum > 2 * max_num) printf("1");
	else printf("0");
	return 0;
}
