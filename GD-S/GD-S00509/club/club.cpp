#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
struct node{int a,b,c;}a[100005];
int q,n,ans,vis[205][205][205];
bool fa,fb;
void dfs(int step,int sa,int sb,int sc,int sum)
{
	if(sa>n/2)return;
	if(sb>n/2)return;
	if(sc>n/2)return;
	if(vis[sa][sb][sc]>=sum)return;
	vis[sa][sb][sc]=sum; 
	if(step>n)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(step+1,sa+1,sb,sc,sum+a[step].a);
	dfs(step+1,sa,sb+1,sc,sum+a[step].b);
	dfs(step+1,sa,sb,sc+1,sum+a[step].c);
}
void dfs(int step,int sa,int sb,int sum)
{
	if(step>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(sa==n/2)
		dfs(step+1,sa,sb+1,sum+a[step].b);
	else if(sb==n/2)
		dfs(step+1,sa+1,sb,sum+a[step].a);
	else if(a[step].a>a[step].b)
		dfs(step+1,sa+1,sb,sum+a[step].a);
	else if(a[step].b>a[step].a)
		dfs(step+1,sa,sb+1,sum+a[step].b);
	else
	{
		dfs(step+1,sa+1,sb,sum+a[step].a);
		dfs(step+1,sa,sb+1,sum+a[step].b);
	}
}
bool cmpA(node a,node b)
{
	return a.a>b.a;
}
bool cmpB(node a,node b)
{
	return abs(a.a-a.b)>abs(b.a-b.b);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> q;
	while(q--)
	{
		cin >> n;
		fa=fb=1;
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			if(a[i].c)fa=fb=0;
			if(a[i].b)fa=0;
		}
		if(fa)
		{
			sort(a+1,a+n+1,cmpA);
			ans=0;
			for(int i = 1;i<=n/2;i++)ans+=a[i].a;
		}
		else if(fb)
		{
			sort(a+1,a+n+1,cmpB);
			ans=0;
			dfs(1,0,0,0);
		}
		else
			dfs(1,0,0,0,0);
		cout << ans << endl;
	}
	return 0;
}
