#include <bits/stdc++.h>
using namespace std;
#define ll long long
int lowbit(int x){return x & -x;}
int n;
struct node
{
	int x,y,z,id;
};
node a[100010],dp[100010];
int l1,l2,l3;
int ans;
void dfs(int now,int num)
{
	if(now == n + 1)
	{
		ans = max(ans,num);
		return;
	}
	if(l1 + 1 <= n / 2)
	{
		l1 ++;
		dfs(now + 1,num + a[now].x);
		l1 --;
	}
	if(l2 + 1 <= n / 2)
	{
		l2 ++;
		dfs(now + 1,num + a[now].y);
		l2 --;
	}
	if(l3 + 1 <= n / 2)
	{
		l3 ++;
		dfs(now + 1,num + a[now].z);
		l3 --;
	}
	return;
}
bool cmp(node i,node j)
{
	return i.x > j.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d",&n);
		bool f = 0;
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i].id = i;
			if(a[i].y != 0 || a[i].z != 0)
				f = 1;
		}
		if(!f)
		{
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n / 2;i ++)
				ans += a[i].x;
			scanf("%d",ans);
			return 0;
		}
		dfs(1,0);
		printf("%d\n",ans);
		ans = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
