#include <bits/stdc++.h>
using namespace std;
int a[5010],sum[5010],ans=0,n;
void dfs(int x,int s)
{
	if(s>n||x<s)
	{
		return;
	}
	dfs(x+a[s+1],s+1);
	if(s>=3&&x>a[s]*2)
	{
		ans++;
	}
	dfs(x-a[s],s+1);
	return;
}
int main()
{	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,0);
	cout << ans%998244353;
	return 0;
}
