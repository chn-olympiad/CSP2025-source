#include<bits/stdc++.h>
using namespace std;
int m,n,da;
int fs[100+5];
int dt[10+5][10+5];
void sr(int x,int q)
{
	if(x%2!=0)
	{
		for(int i=1;i<=n;i++)
		dt[i][x]=fs[q-i+1];
	}
	else if(x%2==0)
	{
		for(int i=n;i>=1;i--)
		dt[i][x]=fs[q-(n-i)];
	}
	return;
}
int main()
{
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>fs[i];
	}
	da=fs[1];
	sort(fs+1,fs+(n*m)+1);
	for(int i=1;i<=m;i++)
	{
		sr(i,m*n-(n*(i-1)));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(dt[i][j]==da)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 