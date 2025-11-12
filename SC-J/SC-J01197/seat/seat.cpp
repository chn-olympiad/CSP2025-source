#include<bits/stdc++.h>
using namespace std;
int n,m,rcj,a[1008],sea[100][100];
bool cmp(int aa,int bb)
{
	return aa>bb;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>rcj;
	a[1]=rcj;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int xx=1,yy=1;
	for(int i=1;i<=n*m;i++)
	{
		sea[xx][yy]=a[i];
		if(xx%2==1)
		{
			if(yy<n)
			{
				yy++;
			}
			else
			{
				xx++;
			}
		}
		else
		{
			if(yy>1)
			{
				yy--;
			}
			else
			{
				xx++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sea[i][j]==rcj)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}