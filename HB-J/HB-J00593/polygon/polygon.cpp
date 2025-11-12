#include <bits/stdc++.h>
using namespace std;
long long da;
long long dda;
int n;
long long gz[5001];
void dfs(long long wz,long long yx,long long maxn,long long sum)
{
	if(wz==n+1)
	{
		return;
	}
	if(yx+1>=3&&(long long)max(maxn,gz[wz])*2<sum+gz[wz])
	{
		da++;
		if(da==998244353)
		{
			dda++;
			da=0;
		}
	}
	dfs(wz+1,yx+1,(long long)max(maxn,gz[wz]),sum+gz[wz]);
	dfs(wz+1,yx,maxn,sum);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>gz[i];
	}
	dfs(1,0,0,0);
	cout<<da;
	return 0;
}
