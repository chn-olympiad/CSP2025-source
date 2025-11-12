#include<bits/stdc++.h>
using namespace std;

const int N=20;
int a[N*N],mp[N][N];
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int fl=a[1],x=1,y=1,fx=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		mp[x][y]=a[i];
		if(fx==1&&x==n)
		{
			fx=0;
			y++;
			continue;
		}
		else if(fx==0&&x==1)
		{
			fx=1;
			y++;
			continue;
		}
		if(fx==1)x++;
		else x--;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==fl)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}