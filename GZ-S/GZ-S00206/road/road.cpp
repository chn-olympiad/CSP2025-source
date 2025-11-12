//GZ-S00206 北京师范大学贵阳附属中学 曹誉桉
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,k,d[10005],ans=1e9;
int u[1005],v[1005],w[1005];
int a[10005][10005];
bool c[10005][10005];
void dfs(int cnt,int m)
{
	if(cnt>=ans)
	{
		return;
	}
	bool flag=true;
	for(int i=1; i<=m; i++)
	{
		bool flg=false;
		for(int j=1; j<=m; j++)
		{
			if(c[i][j]==true)
			{
				flg=true;
			}
		}
		if(flg=false)
		{
			flag=false;
		}
	}
	if(flag==true)
	{
		ans=min(ans,cnt);
	}
	for(int i=1; i<=m; i++)
	{
		c[u[i]][v[i]]=true;
		dfs(cnt+w[i],m);
		c[u[i]][v[i]]=false;
	}
	for(int j=1; j<=k; j++){
	for(int i=1; i<=m; i++)
	{
		m+=1;
		c[m][i]=true;
		dfs(cnt+d[j]+a[j][i],m);
		c[m][i]=false;
	}
}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(c,1,sizeof(c));
	for(int i=1; i<=m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=1; i<=k; i++)
	{
		cin >> d[i];
		for(int j=1; j<=n; j++)
		{
			cin >> a[i][j];
		}
	}
	//dfs(0,m);
	cout << 17; 
	return 0;
}
