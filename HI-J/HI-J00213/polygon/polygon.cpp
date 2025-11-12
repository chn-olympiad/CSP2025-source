#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010];
int ans;
int n;
void dfs(int x,int step,int sum)
{
	if(sum>2*a[x])
	{
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,step+1,sum+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
		{
			flag=1;
		}
	}
	if(!flag)
	{
		for(int i=3;i<=n;i++)
		{
			int num=n-i+1; 
			ans+=(num+1)*num/2;
			ans%=mod;
		}
		printf("%d",ans);
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			dfs(i,1,a[i]);
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
