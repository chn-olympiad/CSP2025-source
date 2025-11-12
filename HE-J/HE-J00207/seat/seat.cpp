#include<bits/stdc++.h>
using namespace std;
int n,m;
int chj[105];
int x,y;
int dfs(int x,int y,int i,int p)
{
	if(chj[i]==p)
	{
		cout<<y<<" "<<x;
		return 0;
	}
	if(y%2!=0)
	{
		x++;
		if(x>n)
		{
			x=n;
			dfs(x,y+1,i+1,p);
		}
		else
		{
			dfs(x,y,i+1,p);
		}
		
	}
	else if(y%2==0)
	{
		x--;
		if(x<1)
		{
			x=1;
			dfs(x,y+1,i+1,p);
		}
		else
		{
			dfs(x,y,i+1,p);
		}
	}
	
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//输入
	cin>>n>>m;
	//输入数组
	for(int i=1;i<=n*m;i++)
	{
		cin>>chj[i];
	}
	//排序 
	//定义变量表示本人成绩 
	int p=chj[1];
	for(int i=1;i<=n*m-1;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(chj[j]<chj[j+1])
			{
				int o=chj[j];
				chj[j]=chj[j+1];
				chj[j+1]=o;
			}	
		}
	} 
	//验证输出
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<chj[i]<<" ";
//	} 
	//开始安排座位

	x=1,y=1;
	dfs(x,y,1,p);
	
	return 0;
	//保存时记得解注释 
}
