#include<bits/stdc++.h>
using namespace std;
int seat[21][21];
int n,m;
struct stu{
	int s;
	int name;
};
stu stu[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>stu[i].s;
		stu[i].name=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(stu[i].s>stu[j].s)swap(stu[i],stu[j]);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!i%2)seat[i][j]=stu[n*(i-1)+j].name;
			else seat[i][n-j+1]=stu[n*(i-1)+j].name;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(seat[i][j]==stu[1].name)
			{
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
}
