#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node
{
	int v,id,clb;
}e[N*3];
int t,n,a[N][4],tot,cnt[4],ans,ans1,ans2,ans3;
bool vis[N];
bool cmp1(node x,node y)
{
	if(x.clb==1&&y.clb!=1)
		return 1;
	else if(x.clb!=1&&y.clb==1)
		return 0;
	else
		return x.v>y.v;
}
bool cmp2(node x,node y)
{
	if(x.clb==2&&y.clb!=2)
		return 1;
	else if(x.clb!=2&&y.clb==2)
		return 0;
	else
		return x.v>y.v;
}
bool cmp3(node x,node y)
{
	if(x.clb==3&&y.clb!=3)
		return 1;
	else if(x.clb!=3&&y.clb==3)
		return 0;
	else
		return x.v>y.v;
}
void dfs(int x,int sum)
{
	if(x>n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;++i)
	{
		if(cnt[i]>=n/2)
			continue;
		cnt[i]++;
		dfs(x+1,sum+a[x][i]);
		cnt[i]--;
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		int now=0;ans=ans1=ans2=ans3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
			{
				scanf("%d",&a[i][j]);
				e[++tot].id=i;
				e[tot].v=a[i][j];
				e[tot].clb=j;
			}
		if(n<=10)
		{
			dfs(1,0);
			printf("%d\n",ans);
			continue; 
		}
		sort(e+1,e+tot+1,cmp1);
		for(int i=1;i<=tot;++i)
		{
			if(vis[e[i].id])
				continue;
			if(cnt[e[i].clb]>=n/2)
				continue;
			ans1+=e[i].v;
			++now;
			vis[e[i].id]=1;
			cnt[e[i].clb]++;
			if(now>=n)
				break;
		}
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		now=0;
		sort(e+1,e+tot+1,cmp2);
		for(int i=1;i<=tot;++i)
		{
			if(vis[e[i].id])
				continue;
			if(cnt[e[i].clb]>=n/2)
				continue;
			ans2+=e[i].v;
			++now;
			vis[e[i].id]=1;
			cnt[e[i].clb]++;
			if(now>=n)
				break;
		}
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		now=0;
		sort(e+1,e+tot+1,cmp3);
		for(int i=1;i<=tot;++i)
		{
			if(vis[e[i].id])
				continue;
			if(cnt[e[i].clb]>=n/2)
				continue;
			ans3+=e[i].v;
			++now;
			vis[e[i].id]=1;
			cnt[e[i].clb]++;
			if(now>=n)
				break;
		}
		printf("%d\n",max(ans1,max(ans2,ans3))); 
	}
	return 0;
} /*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
