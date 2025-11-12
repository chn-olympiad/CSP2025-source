#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[50005],ans,xiah,xia,f1[2005][205][205];
int dfs(int x,int y,int z)
{
	if(2*x<y&&f1[y][x][xiah]==0)
	{
		f1[y][x][xiah]=1;
		ans++;
	}
	for(int i=z;i<=n;i++)
	{	
		if(f[i]==0)
		{
			f[i]=1;
			xiah++;
		
			dfs(max(x,a[i]),y+a[i],z+1);
			xiah--;
			f[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=dfs(0,0,1);
	cout<<ans;
	return 0;
}
