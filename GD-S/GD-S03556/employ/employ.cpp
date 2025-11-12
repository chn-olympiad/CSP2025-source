#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],f[505],ans;
bool easy[505],vis[505];
bool check()
{
	int out=0,pass=0;
	for(int i=1;i<=n;i++)
	{
		if(easy[i]==0 or out>=c[f[i]])out++;
		else pass++;
	}
	return pass>=m;
} 
void dfs(int p)
{
	if(p==n+1)
	{
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;f[p]=i;
			dfs(p+1);
			vis[i]=false;f[p]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=0;i<s.size();i++)
		easy[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
