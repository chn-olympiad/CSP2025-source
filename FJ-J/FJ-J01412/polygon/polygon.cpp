#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353,N = 5005;
int n,a[N],b[15],q[N],cnt;
bool flag = true;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i] == 1)
			cnt++;
		if (a[i] > 1)
		    flag = false;
	}
	if (n<3)
	{
		printf("%d",0);
		return 0;
	}
	if (n == 3)
	{
		int ts = max(a[1],max(a[2],a[3]));
		if (a[1]+a[2]+a[3]>2*ts)
			printf("%d",1);
		else
		    printf("%d",0);
		return 0;
	}
	if (flag)
	{
		if (cnt<3)
		{
			printf("%d",0);
		}
		int ans = cnt*(cnt-1)*(cnt-2)/6,ts = ans,st = 1;
		for (int i = 4;i<n;i++)
		{
			st *= i-3;
			ts *= n-i+1;
			ans += (ts/st)%mod;
		}
		printf("%d",ans+1);
	}
	return 0;
}

