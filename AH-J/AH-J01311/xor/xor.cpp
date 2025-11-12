#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,num;
ll a[500005],mark[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(k==1)
	{
		if(a[1]==1)
		{
			num++;
			mark[1]=1;
		}
		for(ll i=2;i<=n;i++)
		{
			if(a[i]==1)
			{
				num++;
				mark[i]=1;
			}
			if(mark[i-1]==0)
			{
				if((a[i-1]==1&&a[i]==0)||(a[i-1]==0&&a[i]==1))
				{
					num++;
					mark[i]=1;
					mark[i-1]=1;
				}
			}
		}
	} 
	if(k==0)
	{
		if(a[1]==0)
		{
			num++;
			mark[1]=1;
		}
		for(ll i=2;i<=n;i++)
		{
			if(a[i]==0)
			{
				num++;
				mark[i]=1;
			}
			if(mark[i-1]==0)
			{
				if(a[i-1]==1&&a[i]==1)
				{
					num++;
					mark[i]=1;
					mark[i-1]=1;
				}
			}
		}
	}
	printf("%lld",num);
	return 0;
}
