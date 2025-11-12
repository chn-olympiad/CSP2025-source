#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int x,int p,int sum,int maxx,bool o)
{
	if(x>n+1)
	{
		return;
	}
	if(p>=3&&o==1)
	{
		if(sum>maxx*2)
		{
            ans++;
		}
	}
	dfs(x+1,p,sum,maxx,0);
	maxx = max(maxx,a[x]);
	dfs(x+1,p+1,sum+a[x],maxx,1);
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dfs(1,0,0,0,0);
	cout << ans;
	return 0;
}
