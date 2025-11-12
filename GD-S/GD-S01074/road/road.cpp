#include<bits/stdc++.h>
using namespace std;

const int N = 1000005,M=1000005;
int f[N],t[N],w[N],kf[N],kw[N];
int minn = 2e9,n,m,k;
bool is[N],iso[N];

void dfs(int now,int cost,int step)
{
	if(is[now] == 1)return;
	if(step >= n)
	{
		minn = min(minn,cost);
		cout << cost << ' ' << minn << endl;
		return ;
	}
	is[now] = 1;
	for(int i = 1;i<=m;i++)
	{
		if(f[i] == now)
		{
			dfs(t[i],cost+w[i],step+1);
		}
		if(t[i] == now)
		{
			dfs(f[i],cost+w[i],step+1);
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(k != 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i<=m;i++)
	{
		cin >> f[i] >> t[i] >> w[i];
	}
	for(int i = 1;i<=k;i++)
	{
		cin >> kf[i];
	}
	for(int i = 1;i<=k;i++)
	{
		cin >> kw[i];
	}
	dfs(1,0,1);
	cout << minn;
	return 0;
	//我发现我写错了，不会改qwq 
	//预计得分： 0 or 32 
}
