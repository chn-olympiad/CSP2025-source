#include<bits/stdc++.h>
using namespace std;
int ans,t,n;
struct node
{
	int x,y,z;
}a[100005];
void dfs(int sx,int sy,int sz,int cnt,int sum)
{
	if(cnt==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	if(sx<n/2)
	{
		dfs(sx+1,sy,sz,cnt+1,sum+a[cnt].x);
	}
	if(sy<n/2)
	{
		dfs(sx,sy+1,sz,cnt+1,sum+a[cnt].y);
	}
	if(sz<n/2)
	{
		dfs(sx,sy,sz+1,cnt+1,sum+a[cnt].z);
	}
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		ans=0;
		dfs(0,0,0,1,0);
		cout<<ans<<endl;
	}
	return 0;
}
