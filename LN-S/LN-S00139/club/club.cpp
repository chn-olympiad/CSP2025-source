#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5];
int n;
int cnt[5];
int anss=0;
void dfs(int dep,int choise,int sum)
{
	if(dep==n)
	{
		sum+=a[dep][choise];
		if(anss<sum)
		{
			anss=sum;
		}
		return;
	}
	if(cnt[choise]>n/2+1) return;
	for(int i=1;i<=3;i++)
	{
		cnt[i]++;
		dfs(dep+1,i,sum+a[dep][choise]);
		cnt[i]--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		anss=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		dfs(1,1,0);
		printf("%d\n",anss);
	}
	return 0;
}
