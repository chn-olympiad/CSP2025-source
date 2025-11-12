#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int n,k;
int flag,flag1;
int a[N];
int ans;
bool f[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
		{
			flag=1;
		}
		if(a[i]>1)
		{
			flag1=1;
		}
	}
	if(!flag)
	{
		if(k==0)
		{
			printf("%d",n/2);
			return 0;
		}
		else if(k==1)
		{
			printf("%d",n);
			return 0;
		}
		else
		{
			printf("%d",0);
			return 0;
		}
	}
	else if(!flag1)
	{
		if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					ans++;
				}
			}
			printf("%d",ans);
			return 0;
		}
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				else 
				{
					if(a[i-1]==a[i])
					{
						ans++;
						a[i-1]=0;
						a[i]=0;
					}
				}
			}
			printf("%d",ans);
			return 0;
		}
		else
		{
			printf("%d",0);
			return 0;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				ans++;
				f[i]=1;
			}
		}
		printf("%d",ans);
	}
	return 0;
 } 
