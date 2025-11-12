#include<bits/stdc++.h>
using namespace std;

int n,m,c[200010],ans;
string s;
int vis[200010],jl[200010];
void dfs(int now,int cnt,int sum)
{
	if(now==n+1)
	{
		if(sum>=m)
			ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			jl[now]=sum;
//			cout<<sum<<"\n";
			if(c[i]<=cnt||s[now-1]=='0')
				dfs(now+1,cnt+1,sum);
			else
				dfs(now+1,cnt,sum+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","r",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}