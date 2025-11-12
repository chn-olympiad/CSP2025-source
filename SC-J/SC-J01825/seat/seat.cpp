#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int n,m,a[110],d[20][20];
int fx[4]={0,1,-1,0},fy[4]={0,0,0,1};
void fun(int x,int y,int k)
{
	d[x][y]=a[k];
	int tx,ty;
	for(int i=1;i<=3;i++)
	{
		tx=x+fx[i];
		ty=y+fy[i];
		if(tx>0&&tx<=n&&ty>0&&ty<=m&&d[tx][ty]==0)
		{
			fun(tx,ty,k+1);
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	int s=n*m,x;
	for(int i=1;i<=s;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			x=a[i];
		}
	}
	sort(a+1,a+s+1,cmp);
	fun(1,1,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(d[i][j]==x)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
}