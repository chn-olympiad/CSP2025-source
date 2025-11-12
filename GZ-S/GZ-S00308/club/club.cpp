//GZ-S00308   遵义市播州区新蓝学校   王冰洁
#include <bits/stdc++.h>
using namespace std;

const int maxn=100001;
int a[maxn][3],g[3];
int ret; //临时要求的分配方案的满意度的最大值
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int dfs(int n,int f,int lastans)
{
	int n2=n/2;
		for(int i=1; i<=n; i++)
		{
			for(int j=0; i<3; j++)
			{
				if(g[j] < n2)
				{
					g[j]++;
					ret=ret+a[i][j];
					for(int i1=0; i1<4; i++)
					{
						for(int j1=0; j1<4; i++)
						{
						 int nx=i+dx[i1];
						 int ny=j+dy[j1];
						 if(nx>0 && nx<n && ny>0 && ny<4)
						 {
						 	dfs(nx,ny,ret);
						 }
						 else
						 {
						 	break;
						 }
						}
					}
				}
			}
		}
		if(ret>lastans)
		{
			return ret;
		}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//1.定义
	int t; //表示测试数据组数
	long long n;//表示新成员的数量
	cin>>t>>n;
	int ans[t];
	for(int j=0; j<t; j++)
	{
		ans[j]=0;
	}
	
	
	//2.输入
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>a[i][j];
		}
	}
	
	//3.处理
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<3; j++)
		{
			dfs(i,j,ret);
		}
	}
	
	//4.输出 
	for(int i=1; i<=t; i++)
	{
		cout<<ans[i]<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
} 
