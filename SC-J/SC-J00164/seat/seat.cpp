#include <bits/stdc++.h>
using namespace std;

int n,m,b[105];
int a[15][15];

void dfs(int x,int y,int k)
{
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	if(x>=0&&x<=n) a[n][m]=a[x+1][y];
	if(x==n) a[n][m]=a[x][y+1];
	if(y>=1&&y<=m) a[n][m]=a[x][y+1];
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
    cin>>n>>m;
	if(a[n][m]==b[1])
	{
		cout<<a[n][m];
	}
	dfs(1,1,1);
	return 0;
}