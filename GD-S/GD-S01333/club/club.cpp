#include<bits/stdc++.h>
using namespace std;
int a[100001][4],num[100001];
int n,ans;
void dfs(int id,int cnt1,int cnt2,int cnt3,int sum)
{
	if (id==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if (cnt1<(n/2))
	{
		dfs(id+1,cnt1+1,cnt2,cnt3,sum+a[id][1]);
	}
	if (cnt2<(n/2))
	{
		dfs(id+1,cnt1,cnt2+1,cnt3,sum+a[id][2]);
	}
	if (cnt3<(n/2))
	{
		dfs(id+1,cnt1,cnt2,cnt3+1,sum+a[id][3]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	bool flag1;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		flag1=true;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++)
		    {
		    	scanf("%d",&a[i][j]);
		    	if (j>1&&a[i][j]>0)
		    	{
		    		flag1=false;
				}
			}
		}
		if (flag1==true)
		{
			for (int i=1;i<=n;i++)
			{
		        num[i]=a[i][1];
			}
			sort(num+1,num+n+1,greater<int>());
			for (int i=1;i<=n/2;i++)
			{
				ans+=num[i];
			}
			printf("%d\n",ans);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
