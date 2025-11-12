//GZ-S00391 贵州省实验中学 董沁鑫 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4][2],e,b[4],c[4][100010][2]={0},d[4],min0,m;
int main()
{
	freopen("club.in","n",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		d[1]=0;
		d[2]=0;
		d[3]=0;
		b[1]=0;
		b[2]=0;
		b[3]=0;
		for(int j=1;j<=n;j++)
		{
			a[j][1][0]=0;
			a[j][1][1]=0;
			a[j][2][0]=0;
			a[j][2][1]=0;
			a[j][3][0]=0;
			a[j][3][1]=0;
			c[1][j][0]=0;
			c[1][j][1]=0;
			c[2][j][0]=0;
			c[2][j][1]=0;
			c[3][j][0]=0;
			c[3][j][1]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1][0]>>a[i][2][0]>>a[i][3][0];
			a[i][1][1]=1;
			a[i][2][1]=2;
			a[i][3][1]=3;
			for(int j=1;j<3;j++) 
			{
				for(int x=j+1;x<=3;x++)
				{
					if(a[i][j][0]<a[i][x][0])
					{
						e=a[i][j][0];
						a[i][j][0]=a[i][x][0];
						a[i][x][0]=e;
						e=a[i][j][1];
						a[i][j][1]=a[i][x][1];
						a[i][x][1]=e;
					}
				}
			}
			m=0;	
			for(int j=1;j<=3&&m==0;j++) 
			{
				if(b[a[i][j][1]]+1<=n/2)
				{
					d[a[i][j][1]]+=a[i][j][0];
					b[a[i][j][1]]++;
					c[a[i][j][1]][b[a[i][j][1]]][0]=i;
					c[a[i][j][1]][b[a[i][j][1]]][1]=j;
					m=j;
				}
				else
				{
					int min1,min2;
					min0=10000000;
					for(int x=1;x<=n/2;x++)
					{
						if(c[a[i][j][1]][x][1]!=3)
						{
							if(a[c[a[i][j][1]][x][0]][c[a[i][j][1]][x][1]][0]-a[c[a[i][j][1]][x][0]][c[a[i][j][1]][x][1]+1][0]<min0)
							{
								min0=a[c[a[i][j][1]][x][0]][c[a[i][j][1]][x][1]][0]-a[c[a[i][j][1]][x][0]][c[a[i][j][1]][x][1]+1][0];
								min1=c[a[i][j][1]][x][0];
								min2=x;
							}
						}
					}
					if(min0<a[i][j][0]-a[i][j+1][0])
					{
						d[a[i][j][1]]+=a[i][j][0];
						d[a[i][j][1]]-=a[min1][c[a[i][j][1]][min2][1]][0]; 
						c[a[i][j][1]][min2][1]=j;
						e=a[i][1][0];
						a[i][1][0]=a[min1][1][0];
						a[min1][1][0]=e;
						e=a[i][2][0];
						a[i][2][0]=a[min1][2][0];
						a[min1][2][0]=e;
						e=a[i][3][0];
						a[i][3][0]=a[min1][3][0];
						a[min1][3][0]=e;
						e=a[i][1][1];
						a[i][1][1]=a[min1][1][1];
						a[min1][1][1]=e;
						e=a[i][2][1];
						a[i][2][1]=a[min1][2][1];
						a[min1][2][1]=e;
						e=a[i][3][1];
						a[i][3][1]=a[min1][3][1];
						a[min1][3][1]=e;
						j=1;
					}
				}
			}
		}
		cout<<d[1]+d[2]+d[3]<<endl;
	}
	return 0;
 } 
