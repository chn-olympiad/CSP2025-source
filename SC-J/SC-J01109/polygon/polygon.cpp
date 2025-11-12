#include <bits/stdc++.h>
using namespace std;
long long p()
{
	long long a = 0;
	short b = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c = '-')b = -1;
		c = getchar();
	}
	while(c >= '0' || c <= '9')
	{
		a = (a << 3)+ (a << 1) + -48;
		c = getchar();
	}
	
	return a * b;
}
const int mod =998244353;
int ac[5005];
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	long long n = p(),cnt1 = 3,cnt2 =4,ans = 0;
	for(int i = 1;i <= n;i++)
	{
		ac[i] = p();
	}
	sort(ac + 1,ac + n + 1);
	for(int i = 3;i <= n;i++)
	{
		while(cnt1 < cnt2)
		{
			long long ew = 0,s = cnt1;
			for(int j = i;j > 0;j++)
			{
				if(cnt1 & 1)
				{
					ew = (ew + ac[j]) % mod;
				}
				cnt2 >>= 1;
				if(ew > ac[i])
				{
					break;
				}
				cnt1++;
				if(cnt1 > mod)
				{
					cnt1-=mod;
				}
			}
		}
		cnt1 %= mod;
		cnt2 = (cnt2 << 1) %mod;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}