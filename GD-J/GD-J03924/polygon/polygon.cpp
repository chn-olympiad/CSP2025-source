#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool cmp(int x,int y)
{
	return x>y;
}
int res,k;
void dfs(int x,int ans,int maxx)
{
	if(x==n+1)
	{
		if(ans>maxx*2)
		{
			res++;
		}
		return;
	}
	dfs(x+1,ans+a[x],max(maxx,a[x]));
	dfs(x+1,ans,maxx);
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
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		int maxx=max(a[1],max(a[2],a[3]));
		int ans=a[1]+a[2]+a[3];
		if(ans>maxx*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0);
	printf("%d",res);
}


