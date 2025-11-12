#include<bits/stdc++.h>
using namespace std;
int a[500001];
int n,k,ans=0;
void dfs(int id,int sum,int cnt)
{
	if (id==n+1)
	{
		ans=max(ans,cnt);
		return;
	}
	if (cnt+(n-id+1)<=ans)
	{
		return;
	}
    sum^=a[id];
    dfs(id+1,sum,cnt);
    if (sum==k)
    {
    	dfs(id+1,0,cnt+1);
	}
	else
	{
		dfs(id+1,0,cnt);
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int cnt0=0,cnt1=0,maxnum=0;
	bool flag1=true,flag2=true;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxnum=max(maxnum,a[i]);
		if (a[i]!=1)
		{
			flag1=false;
		}
		if (a[i]>1)
		{
			flag2=false;
		}
	}
	if (k>=maxnum*2)
	{
		printf("0");
		return 0;
	}
	if (n==1)
	{
		if (a[1]==k)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		return 0;
	}
	if (flag1==true&&k==0)
	{
		printf("%d",n/2);
		return 0;
	}
	if (flag2==true&&k<=1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0)
			{
				cnt0++;
			}
			else
			{
				cnt1++;
			}
		}
		if (k==0)
		{
			printf("%d",cnt0+cnt1/2);
		}
		else
		{
			printf("%d",cnt1);
		}
		return 0;
	}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
