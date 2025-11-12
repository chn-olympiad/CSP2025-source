#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,pos,tmp,a[200],b[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	tmp=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	x=1;
	y=1;
	pos=1;
	while(pos<=n*m)
	{
		b[x][y]=a[pos];
		if(y%2==1)
		{
			if(x==n)
				y++;
			else
				x++;
		}
		else
		{
			if(x==1)
				y++;
			else
				x--;
		}
		pos++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//~ cerr<<b[i][j]<<' ';
			if(b[i][j]==tmp)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
		//~ cerr<<'\n';
	}
	cout<<-1;
	return 0;
}
