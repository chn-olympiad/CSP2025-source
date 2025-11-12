#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
struct node
{
	int x,y,z;
}a[N];
int t,sum;
bool vis[N];
void dfs(int ans,int xi,int yi,int zi,int s,int i)
{
	if(i > s * 2) 
	{
		sum = max(ans,sum);
		return ;
	}
	if(xi < s and vis[i] == 0)
	{
		vis[i] = 1;
		dfs(ans+a[i].x,xi+1,yi,zi,s,i+1);
		vis[i] = 0;
	}
	if(yi < s and vis[i] == 0)
	{
		vis[i] = 1;
		dfs(ans+a[i].y,xi,yi+1,zi,s,i+1);
		vis[i] = 0;
	}
	if(zi < s and vis[i] == 0)
	{
		vis[i] = 1;
		dfs(ans+a[i].z,xi,yi,zi+1,s,i+1);
		vis[i] = 0;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		memset(vis,0,sizeof(vis));
		sum = 0;
		int n;
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		dfs(0,0,0,0,n/2,1);
		printf("%d\n",sum);
	}
	return 0;
}
