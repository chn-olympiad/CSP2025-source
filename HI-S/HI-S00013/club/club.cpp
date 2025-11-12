#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z;
struct a
{
	int q,id;
}a[4][1005],c;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bool s[1005]={0};
		long long zh=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			a[1][i].q=y+z;a[2][i].q=x+z;a[3][i].q=x+y;
			zh=zh+x+y+z;
			a[1][i].id=i;a[2][i].id=i;a[3][i].id=i;
		}
		for(int k=1;k<=3;k++)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=1;j<=n-i;j++)
				{
					if(a[k][j].q>a[k][j+1].q)
					{
						c=a[k][j+1];a[k][j+1]=a[k][j];a[k][j]=c;
					}
				}
			}
		}
		x=1;y=1;z=1;
		int x1=0,y1=0,z1=0;
		int zx=0;
		while(zx!=n)
		{
			if(a[1][x].q<a[2][y].q and a[1][x].q<a[3][z].q and x1<n/2)
			{
				s[a[1][x].id]=1;
				zh-=a[1][x].q;
				x1++;
				zx++;
				while(s[a[1][x].id]==1)x++;
			}
			else if(a[2][y].q<a[1][x].q and a[2][y].q<a[3][z].q and y1<n/2)
			{
				s[a[2][y].id]=1;
				zh-=a[2][y].q;
				y1++;
				zx++;
				while(s[a[2][y].id]==1)y++;
			}
			else if(z1<n/2)
			{
				s[a[3][z].id]=1;
				zh-=a[3][z].q;
				z1++;
				zx++;
				while(s[a[3][z].id]==1)z++;
			}
			while(s[a[1][x].id]==1)x++;
			while(s[a[2][y].id]==1)y++;
			while(s[a[3][z].id]==1)z++;
		}
		printf("%lld\n",zh);
	}
	return 0;
}
