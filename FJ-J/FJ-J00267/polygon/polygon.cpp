#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],b[5005],n,len,m=0;
void dfs(int x,int sum)
{
	if(sum==len)
	{
		if((b[sum]-b[sum-1])*2<b[sum])
		{
			m++;
		}
		m%=998244353;
		return ;
	}
	for(int i=x+1;i<=n;i++)
	{
		sum++;
		b[sum]=a[i]+b[sum-1];
		dfs(i,sum);
		sum--;
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(len=3;len<=n;len++)
		for(int i=1;i<=n-len+1;i++)
		{
			b[1]=a[i];
		    dfs(i,1);
		}
	printf("%lld",m);
	return 0;
}
