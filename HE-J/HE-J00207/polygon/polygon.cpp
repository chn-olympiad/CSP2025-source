#include<bits/stdc++.h>
using namespace std;
int n;
int mg[5005];
int ans;
//定义函数
int max(int j,int num)
{
	int max1=mg[j];
	for(int i=j;i<j+num;i++)
	{
		if(mg[i]>max1)
		{
			max1=mg[i];
		}
	}
	return max1;
}
bool vis[5005];
//定义找多边形的函数
int f()
{
	for(int i=3;i<=n;i++)
	{
		int a=0;
		for(int j=1;j<=n-2;j++)
		{
			//找木棍
			int o=1; 
			while(o<=n)
			{
				if(!vis[o])
				{
					a+=mg[o];
					vis[o]=true;
				}
				//判断方案是否可行
				if(o>=3&&a>2*max(o,i))
				{
					ans++;
				}
				o++;
			}
		} 
	}
	cout<<ans;
	return 0;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	//输入数组
	for(int i=1;i<=n;i++) 
	{
		cin>>mg[i];
	}
	//找出多边形
	f();
	
	
	return 0;
	//保存时记得解注释 
}
