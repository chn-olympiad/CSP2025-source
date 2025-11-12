#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans1,ans2;
struct st
{
	ll val,id;
}a[105];
bool cmp(st x,st y)
{
	return x.val>y.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	if(n==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a[i].id==1)
			{
				printf("%d %d\n",i,1);
				break;
			}
		}
		return 0;
	}
	if(m==1)
	{
		for(int i=1;i<=n*m;i++)
		{
			if(a[i].id==1)
			{
				printf("%d %d\n",1,i);
				break;
			}
		}
		return 0;
	}
	ans1=ans2=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1) break;
		if(ans1==n)
		{
			if(ans2%2==1)
			{
				ans2++;
			}
			else
			{
				ans1--;
			}
		}
		else
		{
			if(ans1==1)
			{
				if(ans2%2==1)
				{
					ans1++;
				}
				else
				{
					ans2++;
				}
			}
			else
			{
				if(ans2%2==1)
				{
					ans1++;
				}
				else
				{
					ans1--;
				}
			}
		}
	}
	printf("%lld %lld\n",ans2,ans1);
	return 0;
}
