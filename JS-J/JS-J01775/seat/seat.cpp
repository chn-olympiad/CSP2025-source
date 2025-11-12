#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],st[101][101],scoreR,x=1,y=1;
void move()
{
	if(y%2==1)
	{
		if(x<n)
		{
			x++;
		}
		else
		{
			y++;
		}
	}
	else
	{
		if(x>1)
		{
			x--;
		}
		else
		{
			y++;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	scoreR=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int z=1;z<=n*m;z++)
	{
		st[x][y]=a[z];
		move();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(st[i][j]==scoreR)
			{
				cout<<j<<' '<<i;
			}
		}
	}
	return 0;
}
