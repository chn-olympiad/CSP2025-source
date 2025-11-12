#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m=3,b[5005],cnt,c=1;
int ans;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int step)
{
	if(step>m)
	{
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			cnt+=b[i];
		}
		if(cnt>2*b[1])
		{
			ans++;
		}
		return;
	}
	for(int i=c;i<=n;i++)
	{
		b[step]=a[i];
		c=i+1;
		dfs(step+1);
	}
	return;
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
	sort(a+1,a+n+1,cmp);
	for(;m<=n;m++)
	{
		dfs(1);
		ans%=998244353;
		b[1]=0;
		c=1;
	}
	printf("%d",ans);
	return 0;
}
