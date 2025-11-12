#include <bits/stdc++.h>
using namespace std;
const int N=10000;
int a[N],ans=0,n;
bool vis[N];
bool check(int l,int r)//r>l
{
	if(r-l>=2)
	{
		int maxn=0,sum=0;
		for(int i=l;i<=r;i++)
		{
			maxn=max(maxn,a[i]);
			sum+=a[i];
		}
		return sum>2*maxn;
	}
	return 0;
}
void dfs(int l,int r)
{
	if(check(l,r))
	{
		ans++;
		return;
	}
	else
	{
		int flag=0;
		for(int i=l;i<=r;i++)
		{
			if(vis[i])
			{
				flag=1;
			}
		}
		if(flag==0&&r<=n)
		{
			for(int x=0;x<n-2;x++)
			{
				for(int y=0;y<n;y++)
				{
					if(r+y<=n)
					{
						for(int i=l;i<=r;i++)
						{
							vis[i]=1;
						}
						dfs(l+x,r+y);
						for(int i=l;i<=r;i++)
						{
							vis[i]=0;
						}
					}
				}
			}
		}
		else return;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,3);
	cout<<ans;
	return 0;
}
