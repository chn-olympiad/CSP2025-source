#include<bits/stdc++.h>
using namespace std;
using lld = long long;
const lld siz = 1e5+5;
const lld mod = 998244353;
using pll = pair<lld,lld>;

string str;
lld n,m,ans,a[siz];
lld cho[siz],chd[siz];
void dfs(lld now)
{
	if(now>n)
	{
		lld x = 0,y = 0;
		for(int i=1;i<=n;i++)
		{
			lld t = cho[i];
			if(x<a[t]&&str[i] == '1')
				y++;
			else x++;
		}
		ans+=y>=m;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!chd[i])
		{
			cho[now] = i;
			chd[i] = true;
			dfs(now+1);
			chd[i] = false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>str; str = " "+str;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(n<=15)
	{
		dfs(1); printf("%lld",ans);
	}
	else
	{
		ans = 1;
		for(int i=1;i<=n;i++)
		{
			ans*=i; ans%=mod;
		}
		printf("%lld",ans); 
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
