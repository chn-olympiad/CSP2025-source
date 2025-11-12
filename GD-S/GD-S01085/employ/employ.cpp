#include<bits/stdc++.h>
using namespace std;
#define N 510
#define int long long
#define mod 998244353
int n,m,a[N],ans,c[N];
bool b[N],vis[N];
void dfs(int x)
{
	if(x>n)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(s>=a[c[i]])
			{
				s++;
				continue;
			}
			if(!b[i]) s++;
		}
		if(n-s>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			c[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char w;
		cin>>w;
		b[i]=w-'0';	
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
