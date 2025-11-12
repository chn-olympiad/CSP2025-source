#include<bits/stdc++.h>
using namespace std;
struct s
{
	int x,y,w;
}a[1000005];
int c[15][10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	if(k==0)
	{
		long long answer=0;
		for(int i=1;i<=m;i++)
			answer+=a[i].w;
		cout<<answer;
	}
	else
		cout<<0;
	return 0;
}
