#include<bits/stdc++.h>
using namespace std;
int n,m,b[15],a[15],cnt,ans,vis[15],f=1;
string s;
void dfs(int x)
{
	if(x>n)
	{
		if(m<=n-cnt)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
			continue;
		if(b[x]==0)
		{
			cnt++;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			cnt--;
		}
		else if(a[i]>cnt)
		{
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
		else
		{
			cnt++;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
			cnt--;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		int x=s[i]-'0';
		b[i]=x;
		f&=x;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(f==1)
	{
		for(int i=1;i<=n;i++)
			ans*=i;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
