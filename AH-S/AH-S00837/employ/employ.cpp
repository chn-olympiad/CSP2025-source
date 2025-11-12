#include<bits/stdc++.h>
using namespace std;
int n,m,p[510],flg[510],k;char c[510];long long ans;
void dfs(int step,int s)
{
	if(n-s<m)return ;
	if(step==n+1)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(flg[i]==0)
		{
			flg[i]=1;
			if(p[i]<=s)
				dfs(step+1,s+1);
			else
			{
				if(c[step]=='0')
					dfs(step+1,s+1);
				else
					dfs(step+1,s);
			}
			flg[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='1')k=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	if(k==0)
	{
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
