#include <bits/stdc++.h>
using namespace std;
namespace WfhKing{void Main();}
signed main(){return WfhKing::Main(),0;}
namespace WfhKing
{
	int n,m;
	int a[505],now[505];
	bool iab[505];
	int vis[505];
	int ans = 0;
	void solve(int p)
	{
		if(p == n+1)
		{
			int cnt = 0,nowans = 0;
			for(int i=1;i<=n;i++)
			{
				if(cnt >= now[i] || iab[i]==0){cnt++;continue;}
				else nowans++;
			}
			//rintf("%d\n",nowans);
			if(nowans >= m) ans ++;
		}else
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]) continue;
				vis[i] = 1;now[p] = a[i];
				solve(p+1);
				vis[i] = 0;
			}
		}
	}
	void Main()
	{
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		scanf("%d%d",&n,&m);
		string s;
		cin>>s;
		for(int i=1;i<=n;i++){if(s[i-1] == '1') iab[i] = 1;else iab[i] = 0;} 
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		solve(1);
		printf("%d",ans);
		return ;
	}
}
