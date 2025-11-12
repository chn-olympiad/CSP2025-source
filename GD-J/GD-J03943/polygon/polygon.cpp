#include <bits/stdc++.h>
using namespace std;
long long ans;
int n;
int num[5005];
int qy = 998244353;
void dfs(int sy,int sum,int cmax)
{
	if(sy == n+1)
	{
		if(sum > 2*cmax)ans++;
		ans %= qy;
		return;
	}
	dfs(sy+1,sum+num[sy],max(cmax,num[sy]));
	dfs(sy+1,sum,cmax); 
}
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>num[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5
*/
