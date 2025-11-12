//GZ-S00206 北京师范大学贵阳附属中学 曹誉桉
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],cnt;
void dfs(int step,int x,int y,int z,long long ans)
{
	if(x>n/2 || y>n/2 || z>n/2)
	{
		return;
	}
	if(step>n)
	{
		cnt=max(cnt,ans);
		return;
	}
	dfs(step+1,x+1,y,z,ans+a[step][1]);
	dfs(step+1,x,y+1,z,ans+a[step][2]);
	dfs(step+1,x,y,z+1,ans+a[step][3]);
}
int main()
{
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	cin >> t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cnt=0;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=3; j++)
			{
				cin >> a[i][j];
			}
		}
		dfs(0,0,0,0,0);
		cout << cnt << endl;
	}
	return 0;
}
