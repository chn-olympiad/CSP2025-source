#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[505],t[505];string s;bool vis[505];
void dfs(int k,int cnt,int num)
{
	if(k==n+1)
	{
		if(cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			if(num>=a[i]||s[k]=='0')
				dfs(k+1,cnt,num+1);
			else dfs(k+1,cnt+1,num);
			vis[i]=0;
		}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,0,0);
	cout<<ans%998244353;
	return 0;
}
