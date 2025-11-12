#include<bits/stdc++.h>
using namespace std;
int n,ans,a[10000];
void dfs(int idx,int x,int sum,int k)
{
	if(idx > n)
	{
		if(k >= 3 && x * 2 < sum)
			ans++;
		return;
	}
	dfs(idx + 1,max(x,a[idx]),sum + a[idx],k + 1);
	dfs(idx + 1,x,sum,k);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
