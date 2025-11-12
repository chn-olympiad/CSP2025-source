#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a,n,x,y,z,min,mini,xsum,ysum,zsum,sum,aa,bb,cc;
	cin>>a;
	int b[a+1][n+1][4],o[3];
	int xa[n],ya[n],za[n];
	for(int i=0;i<a;i++)
	{
		cin>>n;
		mini=-1;
		xsum=0;
		ysum=0;
		zsum=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d%d%d",&aa,&bb,&cc);
			b[i][j][0]=aa;
			b[i][j][1]=bb;
			b[i][j][2]=cc;
			o[0]=aa;
			o[1]=bb;
			o[2]=cc;
			if(b[i][j][0]>b[i][j][1]&&b[i][j][0]>b[i][j][2])
			{
				x++;
				xa[x]=b[i][j][0];
				if(x>n/2)
				{
					for(int k=0;k<x;k++)
					{
						if(xa[k]<=mini)
						{
							mini=xa[k];
							min=x;
						}
					}
					mini=-1;
					xa[min]=xa[x];
					x--;
				}
			}
			else if(b[i][j][1]>b[i][j][2]&&b[i][j][1]>b[i][j][0])
			{
				y++;
				ya[y]=b[i][j][1];
				if(y>n/2)
				{
					for(int k=0;k<y;k++)
					{
						if(ya[k]<=mini)
						{
							mini=ya[k];
							min=y;
						}
					}
					mini=-1;
					ya[min]=ya[y];
					y--;
				}
			}
			else
			{
				z++;
				za[z]=b[i][j][2];
				if(z>n/2)
				{
					cout<<1;
					for(int k=0;k<5;k++)
					{
						if(za[k]<=mini)
						{
							mini=za[k];
							min=z;
						}
					}
					mini=-1;
					za[min]=za[z];
					z--;
				}
			}
		}
		for(int j=1;j<=x;j++)
		{
			xsum+=xa[j];
		}
		for(int j=1;j<=y;j++)
		{
			ysum+=ya[j];
		}
		for(int j=1;j<=z;j++)
		{
			zsum+=za[j];
		}
		sum=xsum+ysum+zsum;
		printf("%d\n",sum);
	}
}