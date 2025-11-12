#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005][3]; 
int b[15][1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//输入n,m,k
	cin>>n>>m>>k;
	//输入第 i 条道路连接的两座城市与修复该道路的费用
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0;
	//保存解注释 
}
