#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int g[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
		cin>>g[i];
	}
	int f=g[1],flag=1;
	int x=1,y=1;
	sort(g+1,g+1+n*m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
	    {
			
			a[x][y]=g[n*m+1-flag];
			flag++;
			
			if(y%2==1) x++;
			if(y%2==0) x--;
			if(x==n+1)
			{
				x=n;
				y++;
			}
			if(x==0)
			{
				x=1;
				y++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
	    {
			if(a[i][j]==f)
			cout<<j<<" "<<i;
		}
	}
    return 0;
    }
