#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,a[50],f[50],MOD = 998244353,ans;
ll getmax(ll b[],ll len)
{
	ll num = 0;
	for(ll i = 1;i <= len;i ++)
		num = max(num,b[i]);
	return num;
}
ll getall(ll b[],ll len)
{
	ll num = 0;
	for(ll i = 1;i <= len;i ++)
		num += b[i];
	return num;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(ll i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	if(n > 50)
	{
		if(getmax(a,n) == 1)
		{
			ll q[5010];
			q[1] = 1;
			q[0] = 1;
			for(int i = 2;i <= n;i ++)
				q[i] = (q[i - 1] * i + MOD)% MOD;
			for(int i = 3;i <= n;i ++)
				ans = (ans + q[n] / (q[i] * q[n - i])) % MOD;
			printf("%d",ans % MOD);
			return 0;
		}
		printf("0");
		return 0;
	}
	ll x = 1,num = n;
	while(num --)
		x *= 2;
	for(ll i = 1;i < x;i ++)
	{
		ll b[50],flag = 0,j = 0;
		num = i * 2;
		while(num > 0)
		{
			num >>= 1;
			j ++;
			if((num & 1) == 0)
				continue;
			b[++flag] = a[j];
		}
		if(getmax(b,flag) * 2 < getall(b,flag))
		{
			ans ++;
			ans %= MOD;
		}
	}
	printf("%d",ans % MOD);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
