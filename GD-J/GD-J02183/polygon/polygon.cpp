#include<bits/stdc++.h>
using namespace std;
int s[5141];
int n,ans,cntst;
bool f[5141];

void dfs(int x)
{
	if(x==n+1)
	{
		if(cntst>2)
		{
			int cnt=0,maxia;
			for(int i=1;i<=n;i++)
			{
				if(f[i])
				{
					maxia=s[i];
					cnt+=s[i];
				}
			}
			if(cnt>2*maxia)
			{
				ans++;
//				for(int i=1;i<=n;i++)//
//				{
//					cout<<f[i]<<" ";
//				}
//				cout<<endl;//
			}
		}
		return;
	}
	f[x]=0;
	dfs(x+1);
	f[x]=1;
	cntst++;
	dfs(x+1);
	cntst--;
	f[x]=0;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+1,s+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}
//kmax:1048576 smax:500000

//4 0
//2 1 0 3
