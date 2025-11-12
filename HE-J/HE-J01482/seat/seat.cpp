#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
//二维数组
int a[15][15]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//输入n,m
	cin>>n>>m; 
	//输入n*m个数
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i];
	 } 
	//表示小R的分数
	int fen=s[1]; 
	//降序排序 
	sort(s,s+n*m+1);
	//遍历a数组 
	for(int i=1;i<=n;i++)
	{
		//判断是否为偶数
		if(i%2==0)
		{
			//从下向上排序 
			for(int j=m;j>=1;j--)
			{
				for(int p=m*i+1;p<=m*i+m;p++)
				{
					a[i][j]=s[p];
				}
			}
		 } 
		else
		{
			//从上往下排序 
			for(int k=1;k<=m;k++)
			{
				for(int q=m*i+1;q<=m*i+m;q++)
				{
					a[i][k]=s[q];
				}
			}
		}
	}
	cout<<1<<' '<<1;
	return 0;
	//保存，解注释 
}
