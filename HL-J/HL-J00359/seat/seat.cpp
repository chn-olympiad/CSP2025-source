#include<bits/stdc++.h>
using namespace std;

int n,m,r,b[15][15];

struct score
{
	int num,f;
}a[150];

bool cmp(score c,score d)
{
	return c.f>d.f;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
	    cin>>a[i].f;
	    a[i].num=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1,cnt=0;
	while(y<=m)
	{
		while(x<=n)
		{
		  b[x][y]=a[++cnt].num;
		  x++;
		}
		x--;
		y++;
		if(y>m)
		  break;
		while(x>=1)
		{
			b[x][y]=a[++cnt].num;
			x--;
		}
		x++;
		y++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==1)
			{
			   cout<<j<<" "<<i<<"\n";
			   return 0;
			}
		}
	}
	return 0;
}
