#include <iostream>
#include <unordered_map>
using namespace std;
#define int long long
int n;
int ccnt;
int a[5010];
int totl,maxl;
unordered_map<int,bool>mp;
void dfs(int i,int tot,int maxl,int cnt,int way)
{
	if(i==n+1)
	{
		if(mp.count(way)==0)
		{
			mp[way]=1;
			ccnt++;
			ccnt%=998244353;
		}
		return;
	}
	if(cnt>=3)
	{
		if(max(maxl,a[i])*2<tot+a[i])
		{
			dfs(i+1,tot+a[i],max(maxl,a[i]),cnt+1,((way<<1)+1));
		}
		else
		{
			dfs(i+1,tot,maxl,cnt,(way<<1));
		}
		return;
	}
	dfs(i+1,tot+a[i],max(maxl,a[i]),cnt+1,((way<<1)+1));
	dfs(i+1,tot,maxl,cnt,(way<<1));
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		totl+=a[i];
		maxl=max(maxl,a[i]);
	}
	if(n==3)
	{
		if(maxl*2<totl)
		{
			cout<<1<<'\n';
		}
		else
		{
			cout<<0<<'\n';
		}
		return 0;
	}
	dfs(1,0,0,0,0);
	cout<<ccnt;
}
