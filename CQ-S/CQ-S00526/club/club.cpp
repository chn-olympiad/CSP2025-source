#include <bits/stdc++.h>
using namespace std;
#define ll long long
namespace Jayfeather
{
	int T,n,maxx,d[39],a[39],b[39],c[39],cnt1,cnt2,cnt3;
	void dfs(int dep)
	{
		if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return ;
		if(dep==n+1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(d[i]==1) ans+=a[i];
				if(d[i]==2) ans+=b[i];
				if(d[i]==3) ans+=c[i];
			}
			maxx=max(maxx,ans);
			return ;
		}
		cnt1++;
		d[dep]=1;
		dfs(dep+1);
		cnt1--;
		cnt2++;
		d[dep]=2;
		dfs(dep+1);
		cnt2--;
		cnt3++;
		d[dep]=3;
		dfs(dep+1);
		cnt3--;
	}
	signed main()
	{
		cin>>T;
		while(T--)
		{
			maxx=0;
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i]>>b[i]>>c[i];
			}
			dfs(1);
			cout<<maxx<<'\n';
		}
		return 0;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	return Jayfeather::main();
} 
/*
time: 0.03/1s
mem: 0.58/512MB
*/
