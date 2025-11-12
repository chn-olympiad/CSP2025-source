#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,sum[25001000],a[5050],ans=0;
void dfs(int x,int cnt,int last)
{
	if(x>n)
	{
		for(int i=last+1;i<=n;i++)
		{
			if(cnt>a[i])
			{
				ans++;
				ans%=mod;
			}
		}
		return;
	}
	dfs(x+1,cnt+a[x],x);
	dfs(x+1,cnt,last);
	return;
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
/*
5
1 2 3 4 5
*/
