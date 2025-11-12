#include<bits/stdc++.h>
using namespace std;
int n,m,c[15],ans,p[15],vis[15],mod=998244353;
char s[15];
void dfs(int k)
{
	if(k>n)
	{
		int num=0,d=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0') d++;
			else
			{
				if(d<c[p[i]]) num++;
				else d++;
			}
		}
		if(num>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ2.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
