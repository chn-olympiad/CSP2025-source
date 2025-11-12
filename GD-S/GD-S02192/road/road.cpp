#include<iostream>
using namespace std;
int a[10005];
int b[10005];
int c[10005];
int m[10005];
int g[10005];
int main()
{
	//freopen(road.in,"r",stdin);
	//freopen(road.out,"w",stdout);
	int x,y,z;
	cin>>x>>y>>z;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int j=0;j<=z;j++)
		{
			cin>>m[j];
			for(int n=0;n<=x;n++)
			{
				cin>>g[n];
			}
		}
	}
	
	return 0;
}
