#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],b[N][N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++)
	{
		b[x][y]=a[i];
		if(y%2)x++;
		else x--;
		if(x==n+1||x==0)
		{
			y++;
			if(x==n+1)x=n;
			else x=1;
		}
	}
	int ansx=0,ansy=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(b[i][j]==k)
			{
				ansx=i;
				ansy=j;
				break;
			}
		if(ansx&&ansy)break;
	}
	printf("%d %d",ansy,ansx);
	return 0;
}
