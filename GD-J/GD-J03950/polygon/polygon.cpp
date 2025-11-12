#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int a[5010];
void dg(int s,int x,int p)
{
	for(int i=x+1;i<=n-p+1;i++)
	{
		if(p!=1) 
		{
			p--;
			dg(s+a[i],i,p);
		}
		else
		{
			if(s>a[i])
			{
				ans++;
				ans%=998244353;
				return;
			}
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int t=3;t<=n;t++)
	{
		dg(0,0,t);
	}
	printf("%lld",ans%998244353);
	return 0;
}
