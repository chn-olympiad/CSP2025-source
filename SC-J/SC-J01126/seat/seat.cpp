#include <bits/stdc++.h>
using namespace std;
int n,m,a1,a[105],s[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
void seat(int x,int y,int i,int d)
{
	if (x>n||y>m)
		return ;
	s[x][y]=a[i];
	if (d==1&&x==n)
		seat(x,y+1,i+1,0);
	else if (d==0&&x==1)
		seat(x,y+1,i+1,1);
	else if (d==1)
		seat(x+1,y,i+1,d);
	else if (d==0)
		seat(x-1,y,i+1,d);
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m,cmp);
	seat(1,1,1,1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]==a1)
			{
				cout<<j<<' '<<i;
				return 0;
			}
}
