#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int mark[5010];
int ret=0;
void dfs(int dep,int cnt)
{
	if (dep==n+1)
	{
		if (cnt>=3)
		{
			int mx=-1;
			int sum=0;
			for (int i=n;i>=1;i--)
			{
				if (mark[i])
				{
					if (mx==-1)
					{
						mx=a[i];
					}
					else
					{
						sum+=a[i];
					}
				}
			}
			if (sum>mx)
			{
				ret=(ret+1)%998244353;
			}
		}
		return ;
	}
	dfs(dep+1,cnt);
	mark[dep]=1;
	dfs(dep+1,cnt+1);
	mark[dep]=0;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	printf("%d",ret);
	return 0;
}
