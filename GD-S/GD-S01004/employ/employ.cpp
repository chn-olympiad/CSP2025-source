#include<bits/stdc++.h>
using namespace std;
long long ci[505],n,m,ans;
bool s[505],vis[505];
void dfs(int k,int c,int pe)
{
	if(n-k+1<m-pe)return ;
	if(k==n+1)
	{
		if(pe>=m)ans++;
		ans%=998244353;
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(c>=ci[i])dfs(k+1,c+1,pe);
			else 
			{
				if(s[k]==1)dfs(k+1,c,pe+1);
				else dfs(k+1,c+1,pe);
			}
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		char ss;
		cin>>ss;
		if(ss=='1')s[i]=1;
		else s[i]=0;	
	}
	for(int i=1;i<=n;++i)cin>>ci[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
