#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num;
//定义邻接矩阵
int a[10015][10015]; 
//定义改造城市费用
int fy[15]; 
//定义深搜函数 
int sw1;
void dfs(int num,int ans)
{
	if(sw1)
	{
		return ;
	}
	//当连接所有地点后
	if(ans==n)
	{
		sw1=true;
		return ;
	} 
	int sw=true;
	int x;
	//找出与本地相连的道路 
	for(int i=ans;i<=n;i++)
	{
		if(a[ans][i]!=0&&sw)
		{
			x=i;
			sw=false;
		}
		if(a[ans][i]<a[ans][x])
		{
			x=i;
		}
	}
	for(int i=n+1;i<=n+k;i++)
	{
		if((a[ans][i]+fy[i])<a[ans][x])
		{
			x=i;
		}
	}
	num+=a[ans][x];
	a[ans][x]=0;
	dfs(num,x);
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//输入
	cin>>n>>m>>k; 
	//输入邻接矩阵
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
	 } 
	for(int i=1;i<=k;i++)
	{
	 	int b,x;
	 	cin>>b;
	 	for(int j=1;j<=m;j++)
	 	{
	 		cin>>x;
	 		a[n+i][j]=x;
	 		a[j][n+i]=x;
		 }
	 	fy[i]=b;
	}
	//调用函数
	int ans=1;
	dfs(num,ans); 
	cout<<num;
	return 0;
	//保存时记得解注释 
 } 
