#include<bits/stdc++.h>
using namespace std;
int m,n,li,dis_x=1,dis_y=1;
int a[20][20];
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>b[i];
		if(i==1)
		{
			li=b[1];
		}
	}
	sort(b+1,b+m*n+1);
	a[1][1]=b[m*n];
	a[n][m]=b[1];
	for(int i=m*n-1;i>1;i--)
	{
		if(dis_y%2==1)
		{
			if(dis_x<n&&dis_y<=m)//不碰墙 
		{
			dis_x+=1;
			a[dis_x][dis_y]=b[i];
		}
		
		else if(dis_x==n&&dis_y<=m)//到最后一行，没到最后一列 
		{
			dis_y+=1;
			a[dis_x][dis_y]=b[i];
		}
		}
		else if(dis_y%2==0){
			if(dis_x>1&&dis_y<=m)//不碰墙 
		{
			dis_x-=1;
			a[dis_x][dis_y]=b[i];
		}
		else if(dis_x==1&&dis_y<=m)//到最后一行，没到最后一列 
		{
			dis_y+=1;
			a[dis_x][dis_y]=b[i];
		}
		
		}
		//cout<<a[dis_x][dis_y]<<' '<<dis_x<<' '<<dis_y<<endl;
	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==li)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
