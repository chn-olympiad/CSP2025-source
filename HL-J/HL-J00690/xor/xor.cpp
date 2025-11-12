#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long a[500005];bool flag[500005];long long n,k; 
long long _xor(long long l,long long r)
{
	long long res = a[l];
	for (long long i = l + 1;i <= r;i++)
	{
		res ^= a[i];
	}
	return res;
}
void flag_down(long long l,long long r)
{
	for (long long i = l;i <= r;i++)
	{
		flag[i] = 1;
	}
}
bool cflag(long long l,long long r)
{
	for (long long i = l;i <= r;i++)
	{
		if (flag[i]) return false;
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (long long i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (long long i = 0;i < n;i++)
	{
		for (long long j = 1;i + j <= n;j++)
		{
			if (_xor(j,j+i) == k && cflag(j,j+i))
			{
				flag_down(j,j+i);
			}
		}
	}
	long long sum = 0;
	for (long long i = 1;i <= n;i++)
	{
		if (flag[i] && !flag[i - 1]) sum++;
	}
	printf("%lld",sum);
	return 0;
}
