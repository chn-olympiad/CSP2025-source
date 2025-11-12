#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],f2=1,ansm,b[10],c[10];
int yh(int x,int y)
{
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	int t=0;
	for(int i=0;x;i++)
	{
		b[i]=x%2;
		x/=2;
	}
	for(int i=0;y;i++)
	{
		c[i]=y%2;
		y/=2;
	}
	for(int i=0;i<10;i++)
	{
		if(c[i]!=b[i])
		{
			t+=pow(2,i);
		}
	}
	return t;
}
void dfs(int x,int ans)
{
	if(x>n)
	{
		ansm=max(ansm,ans);
		return;
	}
	if(a[x]==k)
	{
		dfs(x+1,ans+1);
	}else
	{
		dfs(x+1,ans);
		int t=a[x];
		for(int i=x+1;i<=n;i++)
		{
			t=yh(t,a[i]);
			if(t==k)
			{
				dfs(i+1,ans+1);
				break;
			}
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(f2==1 and a[i]!=1 and a[i]!=0) f2=0;
	}
	if(f2==1)
	{
		int ans=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				else if(a[i+1]==1) ans++,i++;
			}
		}else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
		}
		printf("%d",ans);
		return 0;
	}
	dfs(1,0);
	printf("%d",ansm);
	return 0;
}