#include<bits/stdc++.h>
using namespace std;

int n,m,a[1001],cnt,cs;
map<pair<int,int>,int> mp;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int w)//ÁÐ£¬ÐÐ£¬ÅÅÃû 
{
	mp[{x,y}]=a[w];
	if(x==m&&y==n)
	{
		return;
	}
	if(x%2==0)
	{
		if(y==1)dfs(x+1,y,w+1);
		else dfs(x,y-1,w+1);
	}
	else
	{
		if(y==n)dfs(x+1,y,w+1);
		else dfs(x,y+1,w+1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[++cnt];
	cs=a[1];
	sort(a+1,a+cnt+1,cmp);
	dfs(1,1,1);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[{i,j}]==cs)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
