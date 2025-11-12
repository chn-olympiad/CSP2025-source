#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans,dp[205][5][205];
struct t1
{
	int x,y,z;
	int a,b,c;
}a[100005];
bool cmp(t1 a,t1 b)
{
	return a.x>b.x;
}
bool cmp1(t1 a,t1 b)
{
	if(a.y!=b.y)return a.y<b.y;
	else return a.x>b.x;
}
void dfs(int u,int A,int B,int C,int s)
{
	if(u==n+1)
	{
		ans=max(ans,s);
		return ;
	}
	if(A+1<=n/2)dfs(u+1,A+1,B,C,s+a[u].x);
	if(B+1<=n/2)dfs(u+1,A,B+1,C,s+a[u].y);
	if(C+1<=n/2)dfs(u+1,A,B,C+1,s+a[u].z);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		bool A=1,B=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].a=max({a[i].x,a[i].y,a[i].z});
			a[i].c=min({a[i].x,a[i].y,a[i].z});	
			a[i].b=a[i].x+a[i].y+a[i].z-a[i].a-a[i].c;
			if(a[i].z!=0)
			{
				B=0;
				A=0;
			}
			if(a[i].y!=0)
			{
				A=0;
			}
		}
		if(n<=10)
		{
			dfs(1,0,0,0,0);
		}	
		else if(A)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
		}
		else if(B)
		{			
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].x;
			}
			for(int i=1+n/2;i<=n;i++)
			{
				ans+=a[i].y;
			}
		}
		else 
		{
			dfs(1,0,0,0,0);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
