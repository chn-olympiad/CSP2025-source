#include <bits/stdc++.h>
using namespace std;
long long l[5005],ans=0,n;
void dfs(int maxx,int all,int now,int g)
{
	if(all>maxx*2&&g>=3)
	{
		ans++;
		ans%=998244353;
	}
	if(now>=n+1)
	{
		return ;
	}
	dfs(max(maxx,l[now]),all+l[now],now+1,g+1);
	if(now>=n)
	{
		return ;
	}
	dfs(maxx,all,now+1,g);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	dfs(0,0,1,0);
	ans%=998244353;
	cout<<ans;
	return 0;
}
