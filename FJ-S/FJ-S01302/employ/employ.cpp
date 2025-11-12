#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string nd;
struct s
{
	int num;
	int nx;
};
int ans2=0;
s l[1000000];
int nx;
int n,m;
vector<int>ve;
int st[1000000]={0};
int st2[1000000]={0};
int dfs(int x)
{
	if(x==n+1)
	{
		int cnt=1;
		int sum=0;
		for(int z=1;z<=n;z++)
		{
			st2[z]=0;
		}
		int ans=0;
		for(auto i:ve)
		{
			for(int j=1;j<=n;j++)
			{
				if(l[j].num==i)
				{
					
					for(int z=cnt-1;z>=0;z--)
					{
						if(st2[z]==0)
							break;
						if(st2[z]==1)
							sum++;
					}
					
					if(sum>=l[j].nx)
					{
						st2[cnt]=1;
					}
					else if(nd[cnt]=='0')
					{
						st2[cnt]=1;
					}
				}
			}
			cnt++;
		}
		for(int z=1;z<=n;z++)
		{
			if(st2[z]==0)
				ans++;			
		}
		if(ans>=m)
			ans2++;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]==0)
		{
			st[i]=1;
			ve.push_back(i);
			dfs(x+1);
			st[i]=0;
			ve.pop_back();
		}
	}
}


signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>nd;
	nd=' '+nd;
	for(int i=1;i<=n;i++)
	{
		cin>>nx;
		l[i]={i,nx};
	}
	dfs(1);	
	cout<<ans2%998244353;
	
	
	
	
	
	
}
