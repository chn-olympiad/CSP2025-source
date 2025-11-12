#include<bits/stdc++.h>
using namespace std;
int n,m,k,sum;
int a[100000][4];
int b[11][10001];
bool p[10001];
long long min=100000000000;
int dfs(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][1]==x&&a[i][0]==0&&p[a[i][2]]==0)
		{
			a[i][0]=1;
			p[a[i][2]]=1;
			sum+=a[i][3];
			dfs(a[i][2],y+1);
			a[i][0]=0;
			p[a[i][2]]=0;
			sum-=a[i][3];
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	return 0;
}
